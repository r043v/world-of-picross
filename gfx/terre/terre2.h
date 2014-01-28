/*frame = 1, width=40, height=40*/
const unsigned int terre2[40][10] = {
{0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000},
{0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000},
{0x00000000,0x00000000,0x00000000,0x29297200,0x29292D4D,0x71514D29,0x00DA7271,0x00000000,0x00000000,0x00000000},
{0x00000000,0x00000000,0x4E000000,0x91914D29,0x7191B595,0x092D0929,0x7229292D,0x000000DA,0x00000000,0x00000000},
{0x00000000,0x00000000,0x4D057200,0x91717191,0x9195B595,0x2D2D292D,0x712D2D2D,0x0000B691,0x00000000,0x00000000},
{0x00000000,0x00000000,0x91914D4D,0x95957171,0x2DB69591,0x09292909,0x4D290909,0x00B69571,0x00000000,0x00000000},
{0x00000000,0x92000000,0x71719191,0x91957171,0x2952B6B5,0x09092929,0x29090909,0xB5919571,0x00000000,0x00000000},
{0x00000000,0x91910000,0x7191716D,0x91957171,0x29292D95,0x09090909,0x09090909,0x4D719129,0x00000091,0x00000000},
{0x00000000,0x9191B500,0x71719191,0x91917171,0x0909294D,0x09090909,0x09090905,0x91955109,0x00009191,0x00000000},
{0x00000000,0x719191B6,0x71719171,0x2D4D9191,0x09090929,0x09090909,0x05090509,0x91712D05,0x00B59171,0x00000000},
{0x00000000,0x4D4D2909,0x91919171,0x09299191,0x09090909,0x09090929,0x05050509,0x91292905,0x00292991,0x00000000},
{0x4D000000,0x29090505,0xB6B59171,0x09292DB6,0x09090909,0x09090909,0x05050509,0x91912905,0x912991B1,0x00000000},
{0x05000000,0x29090505,0xD6B6714D,0x092929B6,0x09090909,0x09090909,0x05050909,0x4D292905,0x6D294D6D,0x000000B6},
{0x05720000,0x09090505,0x922D0909,0x0909092D,0x09090909,0x09050509,0x05050909,0x05050505,0x92910505,0x000000B6},
{0x05290000,0x09092905,0x09090909,0x09290909,0x09090909,0x09050509,0x05050909,0x05050505,0xB2720505,0x0000FFB6},
{0x05050000,0x09090905,0x09090909,0x09290909,0x09050909,0x09050509,0x05290909,0x05050505,0x7271DB29,0x0000DA51},
{0x05050000,0x09090905,0x09090909,0x09090909,0x09090509,0x09050905,0x09290929,0x05050505,0xB6FF7205,0x0000DA92},
{0x05050000,0x09090505,0x09090909,0x09090909,0x09290909,0x05050509,0x05090905,0x05050505,0xFFDB0905,0x0000DBFF},
{0x05050000,0x09090905,0x09090909,0x09090909,0x09090909,0x05090909,0x05050505,0x05050505,0xFF960905,0x0000DBFF},
{0x05050000,0x09090905,0x09090909,0x09090909,0x52714D29,0x09292D92,0x05050509,0x09050505,0x92294D05,0x0000DA96},
{0x05050000,0x09090909,0x09290909,0x29090909,0xDAD6712D,0x0951DADA,0x05050909,0x09290505,0x05052909,0x0000DA29},
{0x05050000,0x09090905,0x29090909,0x4D090909,0xFAD6914D,0x4DB5DAFA,0x29292929,0x29512905,0x05050529,0x0000DB29},
{0x05050000,0x09050505,0x09090909,0xB1290909,0xFAD6B191,0xB1DADAFA,0x71914D4D,0x294D2D29,0x05050929,0x00009229},
{0x05050000,0x05050505,0x09090909,0x91090909,0xFFD6B191,0xDADADAFA,0x91914DB6,0x29297171,0x294D4D92,0x00002D05},
{0x05050000,0x05050505,0x09090505,0x91090909,0xFADAD691,0xFADAFAFA,0x292991DA,0x294D9191,0x296D4D4D,0x00007205},
{0x05050000,0x05050505,0x09090505,0x4D090909,0xFADAB591,0xFAD6DADA,0x2929B6FA,0x29916D6D,0x29492929,0x0000B629},
{0x054D0000,0x09050505,0x09090505,0x4D290909,0xDADAB5B1,0xFADAD6DA,0x2929B5FA,0x6D91714D,0x2949494D,0x00000029},
{0x05000000,0x09050505,0x09090505,0x91292909,0xDADAB591,0xD6D6DAFA,0x4D4D29B6,0x91B5B171,0x49494D71,0x00000091},
{0x29000000,0x4D2D2905,0x29294D6D,0x714D4D29,0xFFDAB18D,0xD6DADAFA,0x4D292992,0x9191B591,0x49494D4D,0x00000000},
{0x00000000,0xB1B12905,0x719191B1,0x71714D4D,0xFAD6B18D,0xD6DAD6FA,0x29292DB6,0x49494D4D,0x914D4D4D,0x00000000},
{0x00000000,0xB16D054D,0x9191B1B1,0x71717191,0xFAD6918D,0xDADAD6DA,0x91294DDA,0x4D4D2929,0x00514D49,0x00000000},
{0x00000000,0x8D292900,0x919191B1,0x71919191,0xDAD6918D,0xDADADAFA,0xB1294DD6,0x49914D91,0x00004D49,0x00000000},
{0x00000000,0x29290000,0x9191B191,0x91919191,0xDAB59191,0xD6DADADA,0xD69191B5,0x917191D6,0x00000091,0x00000000},
{0x00000000,0x29000000,0x91917129,0x91917191,0xD6B19191,0x91D6D6D6,0xD6D6D691,0xB1B571B6,0x00000000,0x00000000},
{0x00000000,0x00000000,0x912D2929,0x91919191,0xB19191B1,0x916DB2B1,0xD6B5D6B5,0x00B5B191,0x00000000,0x00000000},
{0x00000000,0x00000000,0x4D4D7100,0x91514D4D,0xB1B1B1B5,0xD6B65191,0xB1B696DA,0x0000B1B1,0x00000000,0x00000000},
{0x00000000,0x00000000,0x4DB60000,0x0909292D,0xD6B6914D,0xDADA9272,0xB69172FA,0x000000DA,0x00000000,0x00000000},
{0x00000000,0x00000000,0x00000000,0x09092DB6,0x2D290909,0x2D29292D,0x00B62D2D,0x00000000,0x00000000,0x00000000},
{0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000},
{0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000}};