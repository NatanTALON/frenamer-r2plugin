#include <r_core.h>
#include <r_anal.h>
#include <cstring>
#include <cstdlib>
#include "nameGenerator.h"


#define CMD_PREFIX "frnm"


static void renameAllFunctions(RCore &core)
{
    NameGenerator ng;
    RList *functions_list = r_anal_get_fcns(core.anal);
    if (functions_list != nullptr)
    {
        for (RListIter *it = functions_list->head; it; it = it->n)
        {
            RAnalFunction *fcn = reinterpret_cast<RAnalFunction*>(it->data);
            if (fcn == nullptr)
                continue;
            if (std::strncmp(fcn->name, "fcn.", sizeof("fcn.")-1) == 0 &&
                !r_anal_function_rename(fcn, ng.generateName(fcn)))
            {
                r_cons_printf("Warning: function %s has not been renamed.\n", fcn->name);
            }
        }
        r_cons_println("Unamed functions have been renamed.");
    }
}

static void renameFunctionAt(RCore &core, ut64 addr)
{
    NameGenerator ng;
    RAnalFunction *fcn = r_anal_get_function_at(core.anal, addr);
    if (fcn == NULL)
    {
        r_cons_printf("No function found at %#llx.\n", addr);
        return;
    }
    if (!r_anal_function_rename(fcn, ng.generateName(fcn)))
    {
        r_cons_println("Name conflict: the generated name already exists.\nFunction have not been renamed.");
        return;
    }
    r_cons_printf("Function name is now : %s.\n", fcn->name);
}

static void printHelp(const RCore &core)
{
    const char* help[] = {
        "Usage: " CMD_PREFIX, "", "# Function renamer plugin.",
        CMD_PREFIX, "", "# Rename all unamed functions with user friendly names",
        CMD_PREFIX"a", " addr", "# Rename fuunction at the given address",
        NULL
    };

    r_cons_cmd_help(help, core.print->flags & R_PRINT_FLAGS_COLOR);
}

static void _cmd(RCore &core, const char* input)
{
    switch (input[0])
    {
    case '\0':
        renameAllFunctions(core);
        break;

    case 'a':
        renameFunctionAt(core, strtoull(input+1, NULL, 0));
        break;
    
    default:
        printHelp(core);
        break;
    }
}


/**
 * R2 console registration method. This method is called
 * after each command typed into r2. If the function wants
 * to respond on provided command, provides response and returns true.
 * Activation method for this function is matching prefix of the input.
 *  -> prefix(input) == CMD_PREFIX
 *
 * Otherwise the function must return false which will indicate that
 * other command should be executed.
 */
static int r2frenamer_cmd(void *user, const char* input)
{
    RCore& core = *(RCore*)user;
    if (std::strncmp(input, CMD_PREFIX, sizeof(CMD_PREFIX)-1) == 0)
    {
        _cmd(core, input+sizeof(CMD_PREFIX)-1);
        return true;
    }
    return false;
}

// Structure containing plugin info
RCorePlugin r_core_plugin_frenamer = {
    /* .name = */"r2frenamer",
    /* .desc = */"Function renamer",
    /* .license = */"",
    /* .author = */"Wahloo",
    /* .version = */"0.1.0",
    /* .call = */r2frenamer_cmd,
    /* .init = */nullptr,
    /* .fini = */nullptr
};


#ifndef CORELIB
#ifdef __cplusplus
extern "C"
#endif
// This will register the r2plugin in r2 console
R_API RLibStruct radare_plugin = {
    /* .type = */ R_LIB_TYPE_CORE,
    /* .data = */ &r_core_plugin_frenamer,
    /* .version = */ R2_VERSION,
    /* .free = */ nullptr,
    /* .pkgname = */ "frename-r2plugin"
};
#endif