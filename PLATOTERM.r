#include "Processes.r"
#include "Menus.r"
#include "Windows.r"
#include "MacTypes.r"
#include "Finder.r"

type 'PLTO' as 'STR ';
resource 'PLTO' (0, purgeable) {
	 "PLATOTerm 0.5"
};

resource 'MENU' (128) {
    128, textMenuProc;
    allEnabled, enabled;
    apple;
    {
        "About PLATOTERM", noIcon, noKey, noMark, plain;
        "-", noIcon, noKey, noMark, plain;
    }
};

resource 'MENU' (129) {
    129, textMenuProc;
    allEnabled, enabled;
    "Terminal";
    {
	"PLATO Mode", noIcon, "P", noMark, plain;
	"TTY Mode", noIcon, "T", noMark, plain;
	"-",noIcon, noKey, noMark, plain;
	"Hang Up",noIcon, "H", noMark, plain;
        "Quit", noIcon, "Q", noMark, plain;
    }
};

resource 'MENU' (130) {
    130, textMenuProc;
    0, enabled;
    "Edit";
    {
        "Undo", noIcon, "Z", noMark, plain;
        "-", noIcon, noKey, noMark, plain;
        "Cut", noIcon, "X", noMark, plain;
        "Copy", noIcon, "C", noMark, plain;
        "Paste", noIcon, "V", noMark, plain;
        "Clear", noIcon, noKey, noMark, plain;
    }
};

resource 'MENU' (131) {
	 131, textMenuProc;
	 allEnabled, enabled;
	 "Settings";
	{
		"300 baud", noIcon, "3", noMark, Plain;
		"1200 baud", noIcon, "1", noMark, plain;
		"2400 baud", noIcon, "2", noMark, plain;
		"9600 baud", noIcon, "6", noMark, plain;
		"19200 baud", noIcon, "9", noMark, plain;
		"38400 baud", noIcon, "8", noMark, plain;
		"57600 baud", noIcon, "7", noMark, plain;
	}
};

resource 'MBAR' (128) {
    { 128, 129, 130, 131 };
};

resource 'SIZE' (-1) {
	dontSaveScreen,
	acceptSuspendResumeEvents,
	enableOptionSwitch,
	canBackground,
	multiFinderAware,
	backgroundAndForeground,
	dontGetFrontClicks,
	ignoreChildDiedEvents,
	is32BitCompatible,
	isHighLevelEventAware,
	onlyLocalHLEvents,
	notStationeryAware,
	reserved,
	reserved,
	reserved,
	reserved,
	256 * 1024,
	256 * 1024
};

data 'ICN#' (128, purgeable) {
	$"0000 0000 0000 7E00 0003 89FC 001E 222C"            /* ......~...��..", */
	$"007F C8F4 0055 7F84 007A AA04 005F D604"            /* ..��.U.�.z�.._�. */
	$"006A BE04 00D5 5404 00BE AC04 00DF F408"            /* .j�..�T..��..��. */
	$"00BF EC08 00DF D808 01BF E808 017F D808"            /* .��..��..��...�. */
	$"01BF E808 017F D808 01BF B008 0157 D008"            /* .��...�..��..W�. */
	$"03AA B008 03F5 5010 031E B060 05E1 E080"            /* .��..�P...�`.��� */
	$"091E 2300 3223 D400 2444 F800 1C89 4000"            /* �.#.2#�.$D�..�@. */
	$"0392 8000 0075 0000 000E 0000 0000 0000"            /* .��..u.......... */
	$"0000 0000 0000 7E00 0003 FFFC 001F FFFC"            /* ......~...��..�� */
	$"007F FFFC 007F FFFC 007F FFFC 007F FFFC"            /* ..��..��..��..�� */
	$"007F FFFC 00FF FFFC 00FF FFFC 00FF FFF8"            /* ..��.���.���.��� */
	$"00FF FFF8 00FF FFF8 01FF FFF8 01FF FFF8"            /* .���.���.���.��� */
	$"01FF FFF8 01FF FFF8 01FF FFF8 01FF FFF8"            /* .���.���.���.��� */
	$"03FF FFF8 03FF FFF0 03FF FFE0 07FF FF80"            /* .���.���.���.��� */
	$"0FFF FF00 3FFF FC00 3FFF F800 1FFF C000"            /* .��.?��.?��..��. */
	$"03FF 8000 007F 0000 000E 0000 0000 0000"            /* .��............. */
};

data 'ics#' (128, purgeable) {
	$"0000 0000 1FF8 7FFE 7FFE E183 EEEF EEEF"            /* .....�.�.������ */
	$"E1EF EFEF EFEF 7FFE 7FFE 1FF8 0000 0000"            /* ������.�.�.�.... */
	$"0000 0000 1FF8 7FFE 7FFE FFFF FFFF FFFF"            /* .....�.�.������� */
	$"FFFF FFFF FFFF 7FFE 7FFE 1FF8 0000 0000"            /* ������.�.�.�.... */
};

data 'icl4' (128, purgeable) {
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0FFF FFF0 0000 0000"            /* .........���.... */
	$"0000 0000 0000 00FF F000 B00F FFFF FF00"            /* .......��.�.���. */
	$"0000 0000 000F FFF0 00B0 00B0 00B0 FF00"            /* ......��.�.�.��. */
	$"0000 0000 0FFF FFFF FF00 B000 FFFF BF00"            /* .....����.�.���. */
	$"0000 0000 0FBB BBBB BFFF FFFF FB0B 0F00"            /* .....��������... */
	$"0000 0000 0FFB BBBB BBBB BBF0 B0B0 BF00"            /* .....������𰰿. */
	$"0000 0000 0FBF FFFF FFBB BFFB 0B0B 0F00"            /* .....�������.... */
	$"0000 0000 0FBB BBBB BBFF FFF0 B0B0 BF00"            /* .....������𰰿. */
	$"0000 0000 FFBB BBBB BBBB BF0B 0B0B 0F00"            /* ....�������..... */
	$"0000 0000 FBBF FFFB BBBB BFB0 B0B0 BF00"            /* ....�����������. */
	$"0000 0000 FBBF FFFF FFFB BF0B 0B0B F000"            /* ....�������...�. */
	$"0000 0000 FBBF 22FF FFFB BFB0 B0B0 F000"            /* ....��"��������. */
	$"0000 0000 FBBF F2F2 2FBB FB0B 0B0B F000"            /* ....����/��...�. */
	$"0000 000F FBFF FFF2 FFBB F0B0 B0B0 F000"            /* ....������𰰰�. */
	$"0000 000F BBFF FFFF FFBB FB0B 0B0B F000"            /* ....�������...�. */
	$"0000 000F BBFF 2FFF FFBB F0B0 B0B0 F000"            /* ....��/���𰰰�. */
	$"0000 000F BBFF 2222 FFBB FB0B 0B0B F000"            /* ....��""���...�. */
	$"0000 000F BBFF FFFF FBBF B0B0 B0B0 F000"            /* ....�����������. */
	$"0000 000F BBBB BFFF FBBF 0B0B 0B0B F000"            /* ....������....�. */
	$"0000 00FF BBBB BBBB BBBF B0B0 B0B0 F000"            /* ...������������. */
	$"0000 00FF FFFF BBBB BBBF 0B0B 0B0F 0000"            /* ...�������...... */
	$"0000 00FF FAAF FFFB BBBF B0B0 BFF0 0000"            /* ...�����������.. */
	$"0000 0FBF FFFA AAAF FFFB 0B0B F000 0000"            /* ...�������..�... */
	$"0000 FBBB BBBF FFFA AAF0 B0FF 0000 0000"            /* ..���������.... */
	$"00FF BBCC 0CCB BBFF FF0F 0F00 0000 0000"            /* .���.˻��....... */
	$"00FB BB0C CC0C BBBB FFFF F000 0000 0000"            /* .��.�.�����..... */
	$"000F FFBB 0CCC 0CCB BF00 0000 0000 0000"            /* ..��.�.˿....... */
	$"0000 00FF FB0C CCFB B000 0000 0000 0000"            /* ...��.���....... */
	$"0000 0000 0FFF BBFF 0000 0000 0000 0000"            /* .....���........ */
	$"0000 0000 0000 FFF0 0000 0000 0000 0000"            /* ......��........ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
};

data 'ics4' (128, purgeable) {
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"000F FFFF FFFF F000 0FFF FFFF FFFF FFF0"            /* ..�����..������� */
	$"0FFF FFFF FFFF FFF0 FFF2 222F F222 22FF"            /* .���������"/�""� */
	$"FFF2 FFF2 FFF2 FFFF FFF2 FFF2 FFF2 FFFF"            /* ���������������� */
	$"FFF2 222F FFF2 FFFF FFF2 FFFF FFF2 FFFF"            /* ��"/������������ */
	$"FFF2 FFFF FFF2 FFFF 0FFF FFFF FFFF FFF0"            /* ��������.������� */
	$"0FFF FFFF FFFF FFF0 000F FFFF FFFF F000"            /* .�������..�����. */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
};

resource 'FREF' (128, purgeable) {
	 'APPL',
	 0,
	 ""
};

resource 'BNDL' (128, purgeable) {
   'PLTO',
   0,          /*resource ID of signature resource: should be 0*/
   {
      'ICN#', {   /*mapping local IDs in 'FREF's to 'ICN#' IDs*/
      0, 128  /*'FREF' w/ local ID 0 maps to 'ICN#' res ID 128*/
      },
      'ics#', {   /*mapping local IDs in 'FREF's to 'ICN#' IDs*/
      0, 128  /*'FREF' w/ local ID 0 maps to 'ICN#' res ID 128*/
      },
      'icl4', {   /*mapping local IDs in 'FREF's to 'ICN#' IDs*/
      0, 128  /*'FREF' w/ local ID 0 maps to 'ICN#' res ID 128*/
      },
      'ics4', {   /*mapping local IDs in 'FREF's to 'ICN#' IDs*/
      0, 128  /*'FREF' w/ local ID 0 maps to 'ICN#' res ID 128*/
      },
      'FREF', {   /*local res IDs for 'FREF's: no duplicates*/
      0, 128
      }
   }
};

data 'ppat' (128) {
	$"0001 0000 001C 0000 004E 0000 0000 FFFF"            /* .........N....�� */
	$"0000 0000 AA55 AA55 AA55 AA55 0000 0000"            /* ....�U�U�U�U.... */
	$"8001 0000 0000 0008 0008 0000 0000 0000"            /* �............... */
	$"0000 0048 0000 0048 0000 0000 0001 0001"            /* ...H...H........ */
	$"0001 0000 0000 0000 0056 0000 0000 AA55"            /* .........V....�U */
	$"AA55 AA55 AA55 0000 0000 0000 0001 0000"            /* �U�U�U.......... */
	$"FFFF FFFF FFFF 0001 0000 0000 0000"                 /* ������........ */
};

data 'ppat' (129) {
	$"0001 0000 001C 0000 004E 0000 0000 FFFF"            /* .........N....�� */
	$"0000 0000 9224 4992 2449 9224 0000 0000"            /* ....�$I�$I�$.... */
	$"8001 0000 0000 0008 0008 0000 0000 0000"            /* �............... */
	$"0000 0048 0000 0048 0000 0000 0001 0001"            /* ...H...H........ */
	$"0001 0000 0000 0000 0056 0000 0000 9224"            /* .........V....�$ */
	$"4992 2449 9224 0000 0000 0000 0001 0000"            /* I�$I�$.......... */
	$"FFFF FFFF FFFF 0001 0000 0000 0000"                 /* ������........ */
};

data 'ppat' (130) {
	$"0001 0000 001C 0000 004E 0000 0000 FFFF"            /* .........N....�� */
	$"0000 0000 DD77 DD77 DD77 DD77 0000 0000"            /* ....�w�w�w�w.... */
	$"8001 0000 0000 0008 0008 0000 0000 0000"            /* �............... */
	$"0000 0048 0000 0048 0000 0000 0001 0001"            /* ...H...H........ */
	$"0001 0000 0000 0000 0056 0000 0000 DD77"            /* .........V....�w */
	$"DD77 DD77 DD77 0000 0000 0000 0001 0000"            /* �w�w�w.......... */
	$"FFFF FFFF FFFF 0001 0000 0000 0000"                 /* ������........ */
};

data 'ppat' (131) {
	$"0001 0000 001C 0000 004E 0000 0000 FFFF"            /* .........N....�� */
	$"0000 0000 AAAA AAAA AAAA AAAA 0000 0000"            /* ....��������.... */
	$"8001 0000 0000 0008 0008 0000 0000 0000"            /* �............... */
	$"0000 0048 0000 0048 0000 0000 0001 0001"            /* ...H...H........ */
	$"0001 0000 0000 0000 0056 0000 0000 AAAA"            /* .........V....�� */
	$"AAAA AAAA AAAA 0000 0000 0000 0001 0000"            /* ������.......... */
	$"FFFF FFFF FFFF 0001 0000 0000 0000"                 /* ������........ */
};

data 'ppat' (132) {
	$"0001 0000 001C 0000 004E 0000 0000 FFFF"            /* .........N....�� */
	$"0000 0000 FF00 FF00 FF00 FF00 0000 0000"            /* ....�.�.�.�..... */
	$"8001 0000 0000 0008 0008 0000 0000 0000"            /* �............... */
	$"0000 0048 0000 0048 0000 0000 0001 0001"            /* ...H...H........ */
	$"0001 0000 0000 0000 0056 0000 0000 FF00"            /* .........V....�. */
	$"FF00 FF00 FF00 0000 0000 0000 0001 0000"            /* �.�.�........... */
	$"FFFF FFFF FFFF 0001 0000 0000 0000"                 /* ������........ */
};

data 'ppat' (133) {
	$"0001 0000 001C 0000 004E 0000 0000 FFFF"            /* .........N....�� */
	$"0000 0000 8822 8822 8822 8822 0000 0000"            /* ....�"�"�"�".... */
	$"8001 0000 0000 0008 0008 0000 0000 0000"            /* �............... */
	$"0000 0048 0000 0048 0000 0000 0001 0001"            /* ...H...H........ */
	$"0001 0000 0000 0000 0056 0000 0000 8822"            /* .........V....�" */
	$"8822 8822 8822 0000 0000 0000 0001 0000"            /* �"�"�".......... */
	$"FFFF FFFF FFFF 0001 0000 0000 0000"                 /* ������........ */
};

data 'ppat' (134) {
	$"0001 0000 001C 0000 004E 0000 0000 FFFF"            /* .........N....�� */
	$"0000 0000 0022 0088 0022 0088 0000 0000"            /* .....".�.".�.... */
	$"8001 0000 0000 0008 0008 0000 0000 0000"            /* �............... */
	$"0000 0048 0000 0048 0000 0000 0001 0001"            /* ...H...H........ */
	$"0001 0000 0000 0000 0056 0000 0000 0022"            /* .........V....." */
	$"0088 0022 0088 0000 0000 0000 0001 0000"            /* .�.".�.......... */
	$"FFFF FFFF FFFF 0001 0000 0000 0000"                 /* ������........ */
};

data 'ppat' (135) {
	$"0001 0000 001C 0000 004E 0000 0000 FFFF"            /* .........N....�� */
	$"0000 0000 00DD 0077 00BD 00ED 0000 0000"            /* .....�.w.�.�.... */
	$"8001 0000 0000 0008 0008 0000 0000 0000"            /* �............... */
	$"0000 0048 0000 0048 0000 0000 0001 0001"            /* ...H...H........ */
	$"0001 0000 0000 0000 0056 0000 0000 00DD"            /* .........V.....� */
	$"0077 00BD 00ED 0000 0000 0000 0001 0000"            /* .w.�.�.......... */
	$"FFFF FFFF FFFF 0001 0000 0000 0000"                 /* ������........ */
};

data 'DLOG' (128) {
	$"0028 0028 0108 0119 0003 0100 0000 0000"            /* .(.(............ */
	$"0000 0080 00"                                       /* ...�. */
};

data 'DITL' (128) {
	$"0007 0000 0000 000D 005B 001D 00A6 8809"            /* .......�.[...��� */
	$"504C 4154 4F54 4552 4D00 0000 0000 000E"            /* PLATOTERM....... */
	$"000B 002E 002B 2002 0080 0000 0000 0026"            /* .....+ ..�.....& */
	$"0047 0037 00BA 8810 4120 504C 4154 4F20"            /* .G.7.��.A PLATO  */
	$"5465 726D 696E 616C 0000 0000 0040 003D"            /* Terminal.....@.= */
	$"004F 00C3 8812 466F 7220 796F 7572 204D"            /* .O.È.For your M */
	$"6163 696E 746F 7368 0000 0000 006C 0034"            /* acintosh.....l.4 */
	$"008F 00CC 8827 5468 6F6D 6173 2043 6865"            /* .�.̈'Thomas Che */
	$"7272 7968 6F6D 6573 0D20 2020 2020 2020"            /* rryhomes�        */
	$"2020 5374 6576 6520 5065 6C74 7A00 0000"            /*   Steve Peltz... */
	$"0000 00C1 0067 00D5 00A1 0402 4F4B 0000"            /* ...�.g.�.�..OK.. */
	$"0000 0055 0072 0068 008F 8802 4279 0000"            /* ...U.r.h.��.By.. */
	$"0000 0095 0021 00B7 00DF 8837 436F 7079"            /* ...�.!.�.߈7Copy */
	$"6C65 6674 2032 3031 3820 4952 4154 412E"            /* left 2018 IRATA. */
	$"4F4E 4C49 4E45 0D53 6565 2066 696C 6520"            /* ONLINE�See file  */
	$"434F 5059 494E 4720 666F 7220 6465 7461"            /* COPYING for deta */
	$"696C 7300"                                          /* ils. */
};

data 'cicn' (128) {
	$"0000 0000 8010 0000 0000 0020 0020 0000"            /* ....�...... . .. */
	$"0000 0000 0000 0048 0000 0048 0000 0000"            /* .......H...H.... */
	$"0004 0001 0004 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0004 0000 0000 0020 0020"            /* ............. .  */
	$"0000 0000 0004 0000 0000 0020 0020 0000"            /* ........... . .. */
	$"0000 FFFF FFFF FFFF FFFF FFFF FFFF FFFF"            /* ..�������������� */
	$"FFFF FFFF FFFF FFFF FFFF FFFF FFFF FFFF"            /* ���������������� */
	$"FFFF FFFF FFFF FFFF FFFF FFFF FFFF FFFF"            /* ���������������� */
	$"FFFF FFFF FFFF FFFF FFFF FFFF FFFF FFFF"            /* ���������������� */
	$"FFFF FFFF FFFF FFFF FFFF FFFF FFFF FFFF"            /* ���������������� */
	$"FFFF FFFF FFFF FFFF FFFF FFFF FFFF FFFF"            /* ���������������� */
	$"FFFF FFFF FFFF FFFF FFFF FFFF FFFF FFFF"            /* ���������������� */
	$"FFFF FFFF FFFF FFFF FFFF FFFF FFFF FFFF"            /* ���������������� */
	$"FFFF 0000 0000 0000 7E00 0003 89FC 001E"            /* ��......~...��.. */
	$"222C 007F C8F4 0055 7F84 007A AA04 005F"            /* ",..��.U.�.z�.._ */
	$"D604 006A BE04 00D5 5404 00BE AC04 00DF"            /* �..j�..�T..��..� */
	$"F408 00BF EC08 00DF D808 01BF E808 017F"            /* �..��..��..��... */
	$"D808 01BF E808 017F D808 01BF B008 0157"            /* �..��...�..��..W */
	$"D008 03AA B008 03F5 5010 031E B060 05E1"            /* �..��..�P...�`.� */
	$"E080 091E 2300 3223 D400 2444 F800 1C89"            /* ���.#.2#�.$D�..� */
	$"4000 0392 8000 0075 0000 000E 0000 0000"            /* @..��..u........ */
	$"0000 0000 0000 0000 0005 0000 FFFF FFFF"            /* ............���� */
	$"FFFF 0001 FFFF 6666 3333 0002 CCCC CCCC"            /* ��..��ff33..���� */
	$"CCCC 0003 7777 7777 7777 0004 2222 2222"            /* ��..wwwwww.."""" */
	$"2222 000F 0000 0000 0000 0000 0000 0000"            /* "".............. */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0FFF FFF0 0000 0000 0000 0000 0000"            /* ...���.......... */
	$"00FF F000 300F FFFF FF00 0000 0000 000F"            /* .��.0.���....... */
	$"FFF0 0030 0030 0030 FF00 0000 0000 0FFF"            /* ��.0.0.0�......� */
	$"FFFF FF00 3000 FFFF 3F00 0000 0000 0F33"            /* ���.0.��?......3 */
	$"3333 3FFF FFFF F303 0F00 0000 0000 0FF3"            /* 33?����........� */
	$"3333 3333 33F0 3030 3F00 0000 0000 0F3F"            /* 33333�00?......? */
	$"FFFF FF33 3FF3 0303 0F00 0000 0000 0F33"            /* ���3?�.........3 */
	$"3333 33FF FFF0 3030 3F00 0000 0000 FF33"            /* 333���00?.....�3 */
	$"3333 3333 3F03 0303 0F00 0000 0000 F33F"            /* 3333?.........�? */
	$"FFF3 3333 3F30 3030 3F00 0000 0000 F33F"            /* ��33?000?.....�? */
	$"FFFF FFF3 3F03 0303 F000 0000 0000 F33F"            /* ����?...�.....�? */
	$"11FF FFF3 3F30 3030 F000 0000 0000 F33F"            /* .���?000�.....�? */
	$"F1F1 1F33 F303 0303 F000 0000 000F F3FF"            /* ��.3�...�.....�� */
	$"FFF1 FF33 F030 3030 F000 0000 000F 33FF"            /* ���3�000�.....3� */
	$"FFFF FF33 F303 0303 F000 0000 000F 33FF"            /* ���3�...�.....3� */
	$"1FFF FF33 F030 3030 F000 0000 000F 33FF"            /* .��3�000�.....3� */
	$"1111 FF33 F303 0303 F000 0000 000F 33FF"            /* ..�3�...�.....3� */
	$"FFFF F33F 3030 3030 F000 0000 000F 3333"            /* ���?0000�.....33 */
	$"3FFF F33F 0303 0303 F000 0000 00FF 3333"            /* ?��?....�....�33 */
	$"3333 333F 3030 3030 F000 0000 00FF FFFF"            /* 333?0000�....��� */
	$"3333 333F 0303 030F 0000 0000 00FF F44F"            /* 333?.........��O */
	$"FFF3 333F 3030 3FF0 0000 0000 0F3F FFF4"            /* ��3?00?�.....?�� */
	$"444F FFF3 0303 F000 0000 0000 F333 333F"            /* DO��..�.....�33? */
	$"FFF4 44F0 30FF 0000 0000 00FF 3322 0223"            /* ��D�0�.....�3".# */
	$"33FF FF0F 0F00 0000 0000 00F3 3302 2202"            /* 3��........�3.". */
	$"3333 FFFF F000 0000 0000 000F FF33 0222"            /* 33���.......�3." */
	$"0223 3F00 0000 0000 0000 0000 00FF F302"            /* .#?..........��. */
	$"22F3 3000 0000 0000 0000 0000 0000 0FFF"            /* "�0............� */
	$"33FF 0000 0000 0000 0000 0000 0000 0000"            /* 3�.............. */
	$"FFF0 0000 0000 0000 0000 0000 0000 0000"            /* ��.............. */
	$"0000 0000 0000 0000 0000"                           /* .......... */
};

data 'ICON' (128) {
	$"0000 0000 0000 7E00 0003 89FC 001E 222C"            /* ......~...��..", */
	$"007F C8F4 0055 7F84 007A AA04 005F D604"            /* ..��.U.�.z�.._�. */
	$"006A BE04 00D5 5404 00BE AC04 00DF F408"            /* .j�..�T..��..��. */
	$"00BF EC08 00DF D808 01BF E808 017F D808"            /* .��..��..��...�. */
	$"01BF E808 017F D808 01BF B008 0157 D008"            /* .��...�..��..W�. */
	$"03AA B008 03F5 5010 031E B060 05E1 E080"            /* .��..�P...�`.��� */
	$"091E 2300 3223 D400 2444 F800 1C89 4000"            /* �.#.2#�.$D�..�@. */
	$"0392 8000 0075 0000 000E 0000 0000 0000"            /* .��..u.......... */
};


