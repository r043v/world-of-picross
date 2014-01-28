/*frame = 1, width=40, height=40*/
const unsigned int terre23[40][10] = {
{0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000},
{0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000},
{0x00000000,0x00000000,0x00000000,0x00000000,0x09292900,0x09090909,0x00000029,0x00000000,0x00000000,0x00000000},
{0x00000000,0x00000000,0x00000000,0x09290929,0x09090909,0x09090509,0x2D090909,0x00000000,0x00000000,0x00000000},
{0x00000000,0x00000000,0x09290000,0x09090909,0x09090909,0x09090925,0x09090505,0x00004D05,0x00000000,0x00000000},
{0x00000000,0x00000000,0x09090900,0x09090909,0x09090909,0x05092929,0x09290505,0x00290509,0x00000000,0x00000000},
{0x00000000,0x00000000,0x09090909,0x09090909,0x4D290909,0x09292951,0x09050509,0x05050509,0x00000000,0x00000000},
{0x00000000,0x09000000,0x09090909,0x09090909,0x914D4D29,0x2DD6DADA,0x05090529,0x05050929,0x00000000,0x00000000},
{0x00000000,0x09090000,0x09090909,0x09090909,0xB591B191,0xD6DAFADA,0x05092929,0x05050905,0x00000005,0x00000000},
{0x00000000,0x09050500,0x09090909,0x09090909,0xD6B59191,0xDADAFAFF,0x05092991,0x05050505,0x00290505,0x00000000},
{0x00000000,0x05050525,0x09050505,0x09090909,0xDAD6B191,0xDADAFAFA,0x29294DB6,0x05050505,0x72050505,0x00000000},
{0x00000000,0x05050505,0x09050505,0x29090909,0xDADAB191,0xDADADADA,0x914DB1DA,0x2505052D,0x52290505,0x00000000},
{0x05000000,0x09050505,0x09090505,0x91290909,0xDADAB5B1,0xDAD6DAFA,0x912DD6FA,0x2929292D,0xB6050509,0x000000B6},
{0x05000000,0x09050505,0x09090505,0x8D4D4D29,0xDADAD691,0xFAD6DADA,0x2929D6FA,0x2D2D7191,0xB6290929,0x00000096},
{0x05290000,0x29050505,0x2D2D4D6D,0x6D6D4D4D,0xFFFAB591,0xD6D6DAFA,0x2929B1D6,0x294D9171,0x922D2929,0x000000DB},
{0x05050000,0x916D2905,0x6D9191B1,0x8D6D6D4D,0xFAFAB591,0xD6DADADA,0x2D29294D,0x294D7171,0x29050929,0x0000B6DB},
{0x05050000,0xB1B19129,0x919191B1,0x8D717191,0xDAFAD691,0xB6D6DAB1,0x2D4D2909,0x2971916D,0x05052992,0x0000DBB6},
{0x05050000,0xB1B6B129,0x91919191,0x8D717191,0xDADAD6B1,0xDADADADA,0x6D2D292D,0x29919191,0x05254D4D,0x0000B629},
{0x05050000,0xB1B18D29,0x91917191,0x91919191,0xFADAD6B1,0xD6DAD6DA,0x91292929,0x4D91B5B5,0x254D4929,0x0000B625},
{0x05050000,0x918D4929,0x91919191,0x91917171,0xDADAD6B1,0xB6DADADA,0x2D4D2909,0x91B19191,0x054D4949,0x0000DB2D},
{0x05050000,0xB18D2909,0x919191B1,0x91B19191,0xD6D6B6B1,0x91D6D6D6,0x29914D29,0x6D914949,0x2529294D,0x0000DB29},
{0x05050000,0x714D2909,0x91919191,0x91B19191,0xD6B5B191,0xB57191B5,0x29B1914D,0x494D4949,0x0929494D,0x0000DA29},
{0x05050000,0x09090505,0x91919171,0xB1B1B191,0x91B1B1B1,0xD6B69151,0x29B5DAD6,0x4D4D4D91,0x2929494D,0x0000B629},
{0x05050000,0x29290905,0x294D4D29,0xB1B1D671,0x4D5191B1,0xD6D6B1B1,0x91D6DAD6,0x4D494D91,0x2949494D,0x00009625},
{0x05050000,0x714D2929,0x0929292D,0xD6B14D09,0xB6914DB5,0xD6D6D6D6,0x71D6D6D6,0x4D294929,0x2949494D,0x00009229},
{0x05250000,0x71290505,0x09092D91,0xD64D0909,0xDAB64DD6,0x92D6DADA,0x912991D6,0x4D4D6DB5,0x2929494D,0x00000029},
{0x05000000,0x09090505,0x09294D29,0x2D090909,0xDA7272B6,0xD652DADA,0xB5B1B1B6,0x4D6D91B1,0x4929494D,0x00000029},
{0x05000000,0x29050505,0x09090909,0x09090909,0x96292909,0xD692DADA,0xD6B19191,0x4D4DB1D6,0x4949494D,0x00000071},
{0x00000000,0x05050505,0x09090929,0x09090909,0x29290909,0x9151B692,0xB5B191B1,0x494991B1,0x2949494D,0x00000000},
{0x00000000,0x09050505,0x29292909,0x09090909,0x09090909,0x912D2909,0x91D6B1D6,0x4D4D914D,0x00494D71,0x00000000},
{0x00000000,0x09050500,0x09090929,0x09090909,0x09090909,0xB5510909,0xB1B591B5,0x918D8D6D,0x006D4D6D,0x00000000},
{0x00000000,0x09050000,0x09290909,0x29290909,0x09090909,0xDAB12D09,0xD6B16DD6,0xD6D691D6,0x0000498D,0x00000000},
{0x00000000,0x05000000,0x09090909,0x09092909,0x29290909,0xB16D4D29,0xD6B591B5,0xB1B5B6D6,0x00000049,0x00000000},
{0x00000000,0x00000000,0x09090909,0x09290909,0x6D292929,0x91716D91,0xD6D6B5B5,0xD6B1D6D6,0x00000000,0x00000000},
{0x00000000,0x00000000,0x09090900,0x09090909,0x4D4D2909,0xD6B5712D,0xB191B1D6,0x00B1D6D6,0x00000000,0x00000000},
{0x00000000,0x00000000,0x09290000,0x09090909,0x29090929,0x512D2909,0xB1B191B5,0x0000D6B1,0x00000000,0x00000000},
{0x00000000,0x00000000,0x00000000,0x09090909,0x29290909,0x914D2929,0xB5B1B191,0x00000000,0x00000000,0x00000000},
{0x00000000,0x00000000,0x00000000,0x092D0000,0x2D512D09,0xB1B14D4D,0x00000000,0x00000000,0x00000000,0x00000000},
{0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000},
{0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000}};