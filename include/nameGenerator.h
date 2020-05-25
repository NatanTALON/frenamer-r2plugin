#ifndef FRENAME_R2PLUGIN_NAME_GENERATOR_H
#define FRENAME_R2PLUGIN_NAME_GENERATOR_H

#include <string>
#include <r_anal.h>

class NameGenerator
{
private:
    const std::string noun_list[231] = {"Aardvark","Albatross","Alligator","Alpaca","Ant","Anteater","Antelope","Ape","Armadillo","Donkey","Baboon","Badger",
    "Barracuda","Bat","Bear","Beaver","Bee","Bison","Boar","Buffalo","Butterfly","Camel","Capybara","Caribou","Cassowary","Cat","Caterpillar","Cattle","Chamois",
    "Cheetah","Chicken","Chimpanzee","Chinchilla","Chough","Clam","Cobra","Cockroach","Cod","Cormorant","Coyote","Crab","Crane","Crocodile","Crow","Curlew","Deer",
    "Dinosaur","Dog","Dogfish","Dolphin","Dotterel","Dove","Dragonfly","Duck","Dugong","Dunlin","Eagle","Echidna","Eel","Eland","Elephant","Elk","Emu","Falcon",
    "Ferret","Finch","Fish","Flamingo","Fly","Fox","Frog","Gaur","Gazelle","Gerbil","Giraffe","Gnat","Gnu","Goat","Goldfinch","Goldfish","Goose","Gorilla",
    "Goshawk","Grasshopper","Grouse","Guanaco","Gull","Hamster","Hare","Hawk","Hedgehog","Heron","Herring","Hippopotamus","Hornet","Horse","Human","Hummingbird",
    "Hyena","Ibex","Ibis","Jackal","Jaguar","Jay","Jellyfish","Kangaroo","Kingfisher","Koala","Kookabura","Kouprey","Kudu","Lapwing","Lark","Lemur","Leopard",
    "Lion","Llama","Lobster","Locust","Loris","Louse","Lyrebird","Magpie","Mallard","Manatee","Mandrill","Mantis","Marten","Meerkat","Mink","Mole","Mongoose",
    "Monkey","Moose","Mosquito","Mouse","Mule","Narwhal","Newt","Nightingale","Octopus","Okapi","Opossum","Oryx","Ostrich","Otter","Owl","Oyster","Panther",
    "Parrot","Partridge","Peafowl","Pelican","Penguin","Pheasant","Pig","Pigeon","Pony","Porcupine","Porpoise","Quail","Quelea","Quetzal","Rabbit","Raccoon",
    "Rail","Ram","Rat","Raven","Red deer","Red panda","Reindeer","Rhinoceros","Rook","Salamander","Salmon","Sand Dollar","Sandpiper","Sardine","Scorpion",
    "Seahorse","Seal","Shark","Sheep","Shrew","Skunk","Snail","Snake","Sparrow","Spider","Spoonbill","Squid","Squirrel","Starling","Stingray","Stinkbug","Stork",
    "Swallow","Swan","Tapir","Tarsier","Termite","Tiger","Toad","Trout","Turkey","Turtle","Viper","Vulture","Wallaby","Walrus","Wasp","Weasel","Whale","Wildcat",
    "Wolf","Wolverine","Wombat","Woodcock","Woodpecker","Worm","Wren","Yak","Zebra","Robot","Kitty","System","Impulse","Juice","Potato","Minion"};

    const std::string adj_list[200] = {"obedient","rich","magnificent","spiteful","disagreeable","legal","brave","ruddy","eager","quack","victorious",
    "exultant","clean","even","thin","like","cruel","dapper","merciful","sharp","languid","new","mountainous","assorted","fancy","regular","sordid",
    "extra-large","tightfisted","tiny","imported","truthful","easy","tough","madly","whimsical","tight","plain","dynamic","bored","high","sedate","amused",
    "illustrious","inquisitive","superficial","sophisticated","disgusting","delicious","possible","tasteless","versed","ethereal","diligent","wry","oafish",
    "dramatic","sore","superb","tall","fine","shocking","gigantic","makeshift","wise","lean","striped","little","gaudy","nosy","cumbersome","longing",
    "gainful","free","three","proud","wrong","lopsided","macabre","mute","evasive","dark","debonair","torpid","homely","draconian","aquatic","tidy",
    "telling","voracious","equal","vagabond","mean","tedious","hallowed","quickest","oval","jealous","heavy","historical","abandoned","aspiring","wiry",
    "acceptable","waggish","eatable","plastic","average","roomy","woozy","incredible","placid","electric","blue","dispensable","best","coward","kind",
    "lavish""doubtful","gusty","guarded","closed","towering","chunky","pink","frightened","feigned","sincere","boundless","rural","plucky","luxuriant",
    "feeble","skillful","kindhearted","two","mature","observant","wistful","sparkling","substantial","awake","opposite","absurd","daily","ossified","spotted",
    "brawny","handy","synonymous","smooth","sick","disturbed","curvy","measly","abashed","coherent","calm","onerous","absorbed","innocent","rhetorical","scrawny",
    "grouchy","symptomatic","spooky","eight","unkempt","jazzy","obscene","detailed","youthful","hurt","hushed","pushy","picayune","vague","puny","fantastic",
    "cautious","parched","present","volatile","bent","caring","stale","tranquil","courageous","old","innate","daffy","breakable","next","receptive","harsh",
    "fearful","pricey","unbecoming","cold"};

    char *generated_name = NULL;

protected:
    std::hash<unsigned long long> hfcn;

public:
    ~NameGenerator();
    char* generateName(RAnalFunction *fcn);
};

#endif