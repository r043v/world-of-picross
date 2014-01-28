/*frame = 1, width=40, height=40*/
const unsigned int terre11[40][10] = {
{0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000},
{0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000},
{0x00000000,0x00000000,0x00000000,0x91000000,0x29292971,0x09090929,0x00002E09,0x00000000,0x00000000,0x00000000},
{0x00000000,0x00000000,0x00000000,0x2E4D2D71,0x29290929,0x29292909,0x00090909,0x00000000,0x00000000,0x00000000},
{0x00000000,0x00000000,0x29000000,0x2D2D2929,0x09292929,0x09090909,0x09090909,0x00000029,0x00000000,0x00000000},
{0x00000000,0x00000000,0x09294D00,0x292D2D29,0x09092929,0x09090909,0x05050509,0x00002929,0x00000000,0x00000000},
{0x00000000,0x00000000,0x29292929,0x29292929,0x29092929,0x09090909,0x05050509,0x00052905,0x00000000,0x00000000},
{0x00000000,0x09000000,0x29292929,0x29292909,0x09292929,0x09090909,0x05050505,0x29290505,0x00000000,0x00000000},
{0x00000000,0x09090000,0x29290929,0x29292909,0x09090929,0x09090909,0x05050505,0x25050505,0x0000004D,0x00000000},
{0x00000000,0x09090900,0x29292909,0x09090909,0x09090909,0x09090909,0x05050505,0x05050505,0x00004D29,0x00000000},
{0x00000000,0x09090929,0x29294D09,0x09090909,0x09090909,0x09090909,0x05050505,0x25050505,0x004D2909,0x00000000},
{0x00000000,0x0909292D,0x09292929,0x09090909,0x09090909,0x09090909,0x05050505,0x05050505,0x4D6D2929,0x00000000},
{0x09000000,0x09090505,0x09092929,0x09090909,0x09090909,0x09090909,0x05050505,0x05050505,0x4D6D2929,0x00000091},
{0x05000000,0x09050505,0x09090909,0x09090909,0x09090909,0x05090909,0x05050505,0x05050505,0x494D2905,0x00000029},
{0x05290000,0x09050505,0x09090909,0x09090909,0x09090909,0x09090909,0x05050505,0x05050505,0x494D2905,0x0000B629},
{0x05050000,0x09090505,0x29290909,0x29090909,0x09090909,0x09090909,0x05050505,0x05050505,0x294D2905,0x00007252},
{0x05050000,0x09050505,0x09090909,0x29090909,0x09090909,0x05090909,0x05050505,0x05050505,0x72712909,0x0000B6DA},
{0x05050000,0x09090505,0x09090909,0x09290909,0x09090909,0x05050909,0x05050505,0x29050505,0xDB722929,0x0000DADB},
{0x05050000,0x09090505,0x09090909,0x09090909,0x29090909,0x05050909,0x05050505,0x29050505,0xFF4D4949,0x0000DADB},
{0x05050000,0x09090505,0x09090909,0x09090909,0x09090909,0x05050909,0x05050505,0x25050505,0xFF91494D,0x0000DBFF},
{0x05050000,0x09090905,0x09090929,0x09090909,0x09090909,0x05050505,0x05050505,0x05050505,0xFF6D4D49,0x0000DBFF},
{0x05050000,0x09090905,0x09090929,0x09090909,0x09090909,0x05050905,0x05050505,0x05050505,0xB6294971,0x0000FFFF},
{0x05050000,0x09090905,0x09090929,0x09090909,0x09090909,0x05050505,0x05050505,0x29050505,0x9249496D,0x0000DADA},
{0x05050000,0x29090905,0x09290909,0x09090909,0x09090909,0x05050505,0x05050505,0x49290505,0xB64D4949,0x0000DAB6},
{0x05050000,0x09090505,0x09090929,0x09090909,0x09090909,0x05050505,0x05050505,0x6D4D0505,0xB66D4949,0x0000DA92},
{0x05290000,0x09090505,0x09090909,0x09090909,0x09090909,0x05090505,0x05050505,0x916D2905,0xB66D4D71,0x0000DA4D},
{0x05000000,0x09090505,0x09090909,0x09090909,0x09090909,0x05050509,0x29050505,0x916D4D49,0x91919191,0x00000092},
{0x05000000,0x09090505,0x09090909,0x09090909,0x09090909,0x05050509,0x916D2905,0x91916D6D,0x914D9191,0x000000B6},
{0x00000000,0x09050505,0x09090909,0x09090909,0x09090909,0x05050509,0x91916D05,0x91919191,0x2D292991,0x00000000},
{0x00000000,0x09090505,0x09090909,0x09090909,0x09090909,0x29050509,0xB5B5B54D,0x71B191B5,0x726D2991,0x00000000},
{0x00000000,0x09090500,0x09090909,0x09090909,0x09092929,0x4D290909,0x91B59191,0x7191B1B5,0x00914D91,0x00000000},
{0x00000000,0x09050000,0x09090909,0x09090909,0x29292929,0x4D2D0909,0xB6B5B591,0x6D71B5B5,0x0000B191,0x00000000},
{0x00000000,0x09000000,0x09090909,0x09090909,0x29292909,0x912D2929,0x95B5B5B1,0x91719595,0x00000071,0x00000000},
{0x00000000,0x00000000,0x09090909,0x09090909,0x29292909,0x91914D29,0x91717191,0x71919595,0x00000000,0x00000000},
{0x00000000,0x00000000,0x09090900,0x09090909,0x29292929,0x294D7129,0x714D2D29,0x00294D71,0x00000000,0x00000000},
{0x00000000,0x00000000,0x05050000,0x09090909,0x29292909,0x51717129,0x294D2929,0x00002D29,0x00000000,0x00000000},
{0x00000000,0x00000000,0x00000000,0x09090905,0x29292929,0x292D9129,0x29092D2D,0x00000000,0x00000000,0x00000000},
{0x00000000,0x00000000,0x00000000,0x292D0000,0x29292D2D,0x2929294D,0x00004E4D,0x00000000,0x00000000,0x00000000},
{0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000},
{0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000}};