/*frame = 1, width=40, height=40*/
const unsigned int terre13[40][10] = {
{0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000},
{0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000},
{0x00000000,0x00000000,0x00000000,0x2D2D0000,0x2E519171,0x9191512E,0x00000000,0x00000000,0x00000000,0x00000000},
{0x00000000,0x00000000,0x00000000,0x512D2929,0x2D512D51,0x2D29292D,0xB6B1B6B6,0x00000000,0x00000000,0x00000000},
{0x00000000,0x00000000,0x2DB60000,0x2D292D2E,0x4D4D292D,0x292D4D2D,0xB1B69592,0x0000D691,0x00000000,0x00000000},
{0x00000000,0x00000000,0x92DAD500,0x2D29292D,0x09090929,0x09090909,0xD6B1712D,0x00D6D6B5,0x00000000,0x00000000},
{0x00000000,0x00000000,0x91B1D6B1,0x29512D2D,0x09292929,0x09090909,0x712D2929,0xB1B591B5,0x00000000,0x00000000},
{0x00000000,0xB1000000,0x2D4DB1B1,0x292D914D,0x09292929,0x09090909,0x712D2909,0x91D6B14D,0x00000091,0x00000000},
{0x00000000,0xD66D0000,0x4D71B1B5,0x292991B1,0x29092929,0x09090929,0x292D0909,0x4D91B54D,0x00006D49,0x00000000},
{0x00000000,0xB1B12900,0x2D2D91B1,0x29292D91,0x29092929,0x09092929,0x094D0909,0x4D719529,0x006D4D49,0x00000000},
{0x00000000,0x91919100,0x4D292971,0x29292D4D,0x09092929,0x09090909,0x29290505,0x71917105,0x00496D49,0x00000000},
{0x00000000,0x71919129,0x29292929,0x2929292D,0x09090929,0x05090909,0x05050505,0x716D2929,0x49494D4D,0x00000000},
{0x25000000,0x292D2929,0x2D292909,0x292E2E2D,0x09090929,0x05090909,0x05050505,0x4D292525,0x29494D6D,0x00000091},
{0x05000000,0x29090905,0x2D292929,0x29292E2E,0x09090929,0x05090909,0x05050505,0x29050505,0x29494D29,0x00000029},
{0x05000000,0x29090905,0x29290929,0x29292929,0x09092929,0x05090909,0x05050505,0x09050505,0x294D7129,0x00000029},
{0x05050000,0x29090909,0x29292929,0x29292929,0x09092929,0x05050909,0x05050505,0x29290505,0x29496D29,0x00007229},
{0x09050000,0x29090909,0x29292929,0x29292929,0x09092929,0x05050909,0x05050505,0x4D050505,0x29494D29,0x00002972},
{0x29290000,0x09090909,0x29292909,0x29292929,0x09090909,0x05050909,0x05050505,0x05050505,0x4D494D29,0x0000B6BA},
{0x2D290000,0x09090929,0x29092909,0x09092929,0x09090909,0x09050909,0x05050505,0x05050505,0x96294D29,0x0000DADB},
{0x29250000,0x29090909,0x2929292D,0x09090909,0x09090909,0x05090909,0x05050509,0x05050505,0xDA4D4905,0x0000DADB},
{0x05050000,0x29090905,0x09292929,0x09090909,0x09090909,0x09090909,0x05050505,0x05050505,0xFFB62905,0x0000DBDB},
{0x05050000,0x29090505,0x09292929,0x09292909,0x09090909,0x05090909,0x05050505,0x05050505,0xFF292925,0x0000FFFF},
{0x05050000,0x09050505,0x09292909,0x09090909,0x09090909,0x05090909,0x05050505,0x09050505,0xDB6D4929,0x0000FFFF},
{0x05050000,0x09090505,0x09090909,0x09090909,0x09090909,0x05090909,0x05050505,0x29050505,0xBA714929,0x0000DADB},
{0x05050000,0x09050505,0x09290909,0x09090909,0x09090909,0x05090909,0x05050505,0x25050505,0x294D6D4D,0x0000DAB6},
{0x05290000,0x09090505,0x29290909,0x29090909,0x09090909,0x05090909,0x05050505,0x05050505,0x4D496D29,0x0000DAB6},
{0x05000000,0x09090505,0x09090909,0x29090909,0x09090909,0x05090909,0x05050505,0x05050505,0x6D494D25,0x000000B6},
{0x05000000,0x09090505,0x09090909,0x29290909,0x09090909,0x05090929,0x05050505,0x05050505,0x6D494929,0x000000B6},
{0x00000000,0x09090505,0x09092909,0x09090909,0x09090909,0x05050909,0x05050505,0x29050505,0x916D6D6D,0x00000000},
{0x00000000,0x09090505,0x09092909,0x09090909,0x09090909,0x05050905,0x05050505,0x29050505,0x0091716D,0x00000000},
{0x00000000,0x09050500,0x09292909,0x09090909,0x09090909,0x05050509,0x05050505,0x49290505,0x00919191,0x00000000},
{0x00000000,0x09050000,0x09292909,0x29090909,0x09090909,0x05050509,0x05050505,0x6D4D2905,0x00006D91,0x00000000},
{0x00000000,0x09000000,0x09090909,0x09090929,0x09090909,0x05050509,0x05050505,0x91916D29,0x00000091,0x00000000},
{0x00000000,0x00000000,0x09090909,0x09090909,0x09090929,0x05050509,0x29050505,0xB1B19191,0x00000000,0x00000000},
{0x00000000,0x00000000,0x09090900,0x09090929,0x09090909,0x05050909,0x91290505,0x00B5B5B1,0x00000000,0x00000000},
{0x00000000,0x00000000,0x09090000,0x09090909,0x09092909,0x09090909,0x916D2909,0x0000B5B5,0x00000000,0x00000000},
{0x00000000,0x00000000,0x00000000,0x09090909,0x09290909,0x09090929,0x91914D09,0x00000000,0x00000000,0x00000000},
{0x00000000,0x00000000,0x00000000,0x09290000,0x29090909,0x29292929,0x0000914D,0x00000000,0x00000000,0x00000000},
{0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000},
{0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000}};