#include "Processes.r"
#include "Menus.r"
#include "Windows.r"
#include "MacTypes.r"
#include "Finder.r"

type 'PLTO' as 'STR ';
resource 'PLTO' (0, purgeable) {
	 "PLATOTerm 0.1"
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
    "File";
    {
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

resource 'MBAR' (128) {
    { 128, 129, 130 };
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
	100 * 1024,
	100 * 1024
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