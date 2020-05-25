#include <cstring>
#include <string>
#include "nameGenerator.h"

NameGenerator::~NameGenerator()
{
    free(generated_name);
}

char* NameGenerator::generateName(RAnalFunction *fcn)
{
    /* select a noun and an adjectif in the list */
    size_t hash = hfcn(fcn->addr);
    int noun_num = hash%231;
    int adj_num = hash%200;

    /* compute the size of the name */
    int n_size = noun_list[noun_num].size() + adj_list[adj_num].size() +1;
    char xrefs[10];
    char calls[10];
    int xrefs_size, calls_size;    
    
    /* every xrefs should be take into account: calls, jumps... */
    xrefs_size = std::snprintf(xrefs, 10, "%d", r_anal_function_get_xrefs(fcn)->length);
    /* We only count the calls for the references. Else all jumps or string load are counted */
    RList *refs_list = r_anal_function_get_refs(fcn);
    int refs_num = 0;
    for (RListIter *it = refs_list->head; it; it = it->n)
    {
        RAnalRef *ref = reinterpret_cast<RAnalRef*>(it->data);
        if (ref == nullptr)
            continue;
        if (ref->type == R_ANAL_REF_TYPE_CALL)
            refs_num++;
    }
    
    calls_size = std::snprintf(calls, 10, "%d", refs_num);

    /* If the number of xrefs or refs are expressed with more than 9 digits, replace the number by + */
    if (xrefs_size == 10)
    {
        xrefs[0] = '+';
        xrefs[1] = '\0';
        xrefs_size = 1;
    }
    if (calls_size == 10)
    {
        calls[0] = '+';
        calls[1] = '\0';
        calls_size = 1;
    }


    /* alloc the name and fill it */
    generated_name = (char*)realloc(generated_name, n_size+xrefs_size+calls_size+4);
    /* random name */
    std::strncpy(generated_name, (adj_list[adj_num]+"_"+noun_list[noun_num]).c_str(), n_size);
    generated_name[n_size] = '_';

    /* function size */
    ut64 function_size = r_anal_function_realsize(fcn);
    if (function_size < 100)
    {
        generated_name[n_size+1] = 's';
    }
    else if (function_size < 500)
    {
        generated_name[n_size+1] = 'm';
    }
    else
    {
        generated_name[n_size+1] = 'l';
    }
    
    /* xrefs and refs */
    std::strncpy(generated_name+n_size+2, xrefs, xrefs_size);
    generated_name[n_size+xrefs_size+2] = '.';
    std::strncpy(generated_name+n_size+xrefs_size+3, calls, calls_size);
    
    /* null character to end the string */
    generated_name[n_size+xrefs_size+calls_size+3] = '\0';
    
    return generated_name;
}