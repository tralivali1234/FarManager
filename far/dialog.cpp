/*
dialog.cpp

����� �������

*/

/* Revision: 1.179 14.11.2001 $ */

/*
Modify:
  14.11.2001 SVS
    ! DN_EDITCHANGE: Path#1047:
      "...��������� ���������� DN_EDITCHANGE ��� ������ �� �������..."
      "...��� ������ � ������ ��������� ��������������� ���������, ��
      ���������� :). ������ ������ ������ ESC'�� � ���������� ��� �����
      ������� DN_EDITCHANGE?..."
      ����,  ���� ��. ��� �� � �������,  ��� ��� ��� COMBOBOX.
  12.11.2001 SVS
    ! ��������� �� ������ ��������� DN_LISTCHANGE (� �.�. ���������� �� �����
      ��������� ����������)
    ! ��������� ���������� DN_EDITCHANGE ��� ������ �� �������
    ! ��������� ��������� DIF_SELECTONENTRY
  09.11.2001 SVS
    - ������� ��� ��������� ���������� � ����������� ������ = 0
  08.11.2001 SVS
    + IsDialogParent - � �������� � ��� ��� ��� ����� ��������������?
    ! ������� � ���� BitFlags - ���������� ������� �������� ������ �������
  06.11.2001 SVS
    ! DM_LIST[G|S]ETTITLE -> DM_LIST[G|S]ETTITLES
    - BugZ#36: �������� � ������������ ������� ����� ������ �������
      �������� ������ �  ��������,  ��������,  alt-f7,  ��������  �������
      (ctrl-down), ��������  ������,  �����  ����������  �������  �������
      ������� ��� �� ���������, ����� ������ �� �������, ����  ����������
      �����/����, �� ���������� ������ ����� �������
      ������� ����� ���� ����� :-( �� ��������.
  04.11.2001 SVS
    ! ���� DropDown ������ �����, �� �� ����� ���������� ��� ��� ��������.
  02.11.2001 SVS
    ! DM_SETNOTIFYMOUSEEVENT -> DM_SETMOUSEEVENTNOTIFY
    ! ������� �������� ��� (� ���-��� ������� :-))
  29.10.2001 SVS
    ! DM_RESIZEDIALOG ���������� ����� ������!
  23.10.2001 SVS
    ! FarListTitle -> FarListTitles
    ! ����������� - � ProcessMouse ������ ����� ��������� � ����� �� ������,
      �.�. ��������� (��� ��) Z-order (IMHO ��� ����� ������, �� ��� ����
      �� �����)
  21.10.2001 SVS
    ! ����� CALLBACK-������� (� ������ DN_RESIZECONSOLE) ��������� � "������ �����"
    ! �������� ������ ���������� � �������:
      "���� � ������� ���� ������, ������ ��� ����� �������� ���,
      ������� ���������, �� ������� ������ ������ � �������� �����".
      (�� ����� ����, ������ ��������� �� ��������, � ����������� ������!)
  18.10.2001 SVS
    + DIF_SEPARATOR2 - ������� ���������
    + ����� CALLBACK-������� (� ������ DN_RESIZECONSOLE)
      ��� ���������� �� BugZ#85
  15.10.2001 SVS
   + _DIALOG - ��� ����������� ��������� � ������� � ��������.
  15.10.2001 SVS
   ! BugZ#71: "���� "��������" ����� ���� DIF_NOFOCUS..." - ������� ����
     ������� ����������� �� 10.10.2001. ������ ��� ����� - ������ � �����
     ������ ����� Unchanged-������
  15.10.2001 SVS
   ! if Opt.DlgSelectFromHistory == 0 then (ctrl-down � ������ � ��������
     ������ �������������� �� ����� ������� ������)
   - "���� � ������� ������� ��� 64 �������� ��������..."
  10.10.2001 SVS
   ! ���� "��������" ����� ���� DIF_NOFOCUS, �� ���������� ��� ����������
     ������ (BugZ#71)
  08.10.2001 SVS
   - ������� �������������� ���������� ��������� DI_TEXT & DI_VTEXT
  04.10.2001 SVS
   ! ������������ �������!!!
     ������� Dialog::DefDlgProc � Dialog::SendDlgMessage ������ ���� ������
     � ����� ����� �����. ���� ���-�� ��������� - �� ����� Dialog::DefDlgProc()
     �����������: ��� ��� ������� ;-)
   - DN_GOTFOCUS -> DM_SETFOCUS - �������� ���� � ��������
  04.10.2001 SVS
   - ��� DI_USERCONTROL �� ������������ ������
  27.09.2001 IS
   - ����� ������ ��� ������������� strncpy
  16.09.2001 SVS
   ! ����������� ����������
  08.09.2001 VVM
   + ������������ Opt.DialogsEditBlock ��� ����� �����
  05.09.2001 SVS
   - ������� �������, ����� ����� ����������, �� ���������� �� ���� :-((
  30.08.2001 VVM
   + ��� ������� ����� ������� ���������� �����
  15.08.2001 SVS
   + DN_MOUSEEVENT, DM_SETNOTIFYMOUSEEVENT, DMODE_MOUSEEVENT
  13.10.2001 SVS
   - ���� � �������� X2 < X1, �� ��� �������� ���� ������ � ����������� � ����.
  11.10.2001 KM
   - ��� ���� ��������� ��� ����������, � ������ ���������������
     ������ ���� ������� �� ������� ������.
  10.08.2001 KM
   - ����������� ������� DM_RESIZEDIALOG. ������� ����� �����
     ��������� Alt-F7 ��� ��������� �������� �������.
   - � SetItemRect ������� ����������� X1 � 0 ��� ����������
     ��������� -1 (������������ ������).
  08.08.2001 SVS
   + DM_GETITEMPOSITION
  07.08.2001 SVS
   + DN_RESIZECONSOLE
  06.08.2001 SVS
   ! DM_GETTEXTLENGTH ���������� ������ ������ ��� ����� '\0'
   ! ��������� ��� ������ ������ ���� DM_SETTEXT ��� ������ ���
     ��������������� ��������� (SetFarTitle(Dlg->GetDialogTitle()))
   ! �������� �� ��������� ������� (����� ������� � ��������� ������,
     ����� ������� ����� �������� Hide() ������� - ��� Alt-F7+CAS)
   ! ������� ��������������� ����� ��� ������ �������������� (2IS: �������
     �� ����)
  05.08.2001 SVS
   ! �������� � ���������� ���������� ������� (Dialog::AddToEditHistory)
   - ���� � ����������� ��� ������ �� �������.
   ! DM_GETTEXTLENGTH ��������� ���������� ������ �������� ����� ��� DI_LISTBOX
   ! ���������� ��������� DI_RADIOBUTTON
       Param2 = 0|1 - ������� ��� ��������
  05.08.2001 SVS
   - �������� � ������ � �������� ��-��� ��������.
   ! ���������(?) ����� DI_EDITCHANGE
   - Ctrl-Enter ��� Enter ��� ������������� ���������� ������
  01.08.2001 SVS
   + ����� ��������� �������� ������ - ����� �� ���� ����������� ���� Help`�
  27.07.2001 SVS
   + DM_ALLKEYMODE - ��� ���� MacroBrowse (���� ������ ��� ���� :-)
  26.07.2001 SVS
   ! VFMenu ��������� ��� �����
  24.07.2001 SVS
   ! ����� ����� ����� Opt.Confirm.HistoryClear ��� ������� �������
  23.07.2001 OT
   - ����������� ��������� ���� � ����� MA � ��������
  23.07.2001 VVM
   + ��� �������� ������ �� ������� ������ ��������� �� �����.
   + ��� ������� ������� �������� �� ���� ������������.
  23.07.2001 SVS
   ! DIF_SEPARATOR ���� �� ������������ ��� DI_VTEXT
  23.07.2001 SVS
   - �� ������������� ������, ������� ��� ������ � DeleteDialogObjects()
  22.07.2001 SVS
   ! ������������ ��������� ������� SelectFromComboBox() - ���� � ���
     �������� ��������� �� �� ������� ����� ������, ��� ���...
  18.07.2001 OT
   !  VFMenu
  16.07.2001 SVS
   + DM_SETHISTORY - ���������� ��������
  12.07.2001 OT
   - ����������� �������� (����� 816) F11->F4->Esc-> :(
  11.07.2001 OT
   ! ������� CtrlAltShift � Manager
  10.07.2001 SVS
   + ��������� KEY_MACROXLAT
  09.07.2001 OT
   - ����������� MacroMode ��� ��������
  04.07.2001 SVS
   + DIF_SEPARATOR ��� DI_VTEXT
   + {-1,-1} ��� DI_VTEXT
  04.07.2001 SVS
   - XLat � ������� ����� - �� ��������� ��������� Unchanged
   - ������� ��������...
  02.07.2001 KM
   - ��������� �� �������������� (� ������� �� ������) ����
     ��� Param1==-1 � SendDlgMessage (� ��������) � DefDlgProc.
   - ������ ��������� �������� �� �������������� ����������.
  30.06.2001 KM
   ! LIFIND_NOPATTER -> LIFIND_NOPATTERN
   ! DM_LISTGETCURPOS: Param2 �������� ��������� �� FarListPos.
   ! DM_LISTSETCURPOS: Param2 �������� ��������� �� FarListPos.
   ! ������� ��������� DN_LISTCHANGE � ProcessMouse �� DI_LISTBOX.
  29.06.2001 SVS
   - ���� - ���� ���������� �������������� ������ � ���������
   + ������������: �� ����� ��������� � �������� ����� (��������)
                   ���������� ��� � ��������� ������ ��������������
                   (��������! :-(
   ! �������� � ������� �� ����������
  26.06.2001 KM
   ! ������� ����� DM_LISTSETCURPOS ��������� DN_LISTCHANGE.
  26.06.2001 SVS
   ! __except -> EXCEPT
  26.06.2001 KM
   - �� ������� ���� �� ��������� � DI_LISTBOX.
  23.06.2001 KM
   - �� �������� ������� ���������� ���������� ���� � ����
     ������� ������ �� DI_EDIT.
   + DM_GETDROPDOWNOPENED - ����������, ������ �� � ������� ��������� ��� �������.
   + DM_SETDROPDOWNOPENED - ������� ��� ������� ����������� ���� ��������� ��� �������.
  20.06.2001 SVS
   - "������� DM_GETTEXTLENGTH ���������� 0 ����� ��� ���� DI_EDIT"
  19.06.2001 SVS
   + DN_DRAGGED
  19.06.2001 SVS
   ! �������� �������������� �� �������� �� ����� ������ � ���������� �������.
   - ���������� ������������� �������� (����� �� ������� �������) ��� ������
     �������� �� �������.
  14.06.2001 SVS
   ! ����� -> VMENU_COLOR_COUNT
  14.06.2001 OT
   - ��� ������->F5->CtrlDown->����
     ������� ����������������� ������ ������ ��� ���� ������� :((
  12.06.2001 KM
   ! �����-�� ���� ������ ������������� DI_COMBOBOX ����� FarDialogItem.
     �������������!!!
  11.06.2001 KM
   ! ������� ���������� ������ ���� � DI_LISTBOX.
  10.06.2001 SVS
   ! ��� DM_LISTFINDSTRING ������� ������� ����� �������.
  08.06.2001 SVS
   + ���� ������� � "����������" �������-������ �� ������� �������...
     ���������� - � ����� ��� ��� �������������, ��� ����� ����������
     ������� �� ������ �������������� �� ��������� �������-����?
  06.06.2001 SVS
   ! Mix/Max
  05.06.2001 KM
   ! ��������� ��� ������������� �������� � DM_LISTSETTITLE - ���� TRUE �
     DM_LISTGETTITLE - ���� TRUE, ���� ������� Title ��� Bottom � FALSE ����
     �� �������� �� ���� �� �������.
  04.06.2001 SVS
   + Shift-Del ������� ������� ����� ������� ������.
  04.06.2001 SVS
   ! ������� LIF_PTRDATA - ����� ���� ��� ����� :-)
   ! SelectFromEditHistory ��������� ����������, � �.�. ��������� ��������
     ��������.
   ! � ����� � ���������� SelectFromEditHistory() ��������� �����������
     ������������ �������������� ���������� ������� ������� (� ������ ������
     64 - ��� ����� ��������, �.�. :-)
   ! AddToEditHistory() - �������� ��� ������ ������ ����� �������.
   + ��� ��������� � ������� ������ ��������, ����� ����������...
     ���������� �������� �������������� ������� �������.
  03.06.2001 KM
   + ��������� ��������� DM_LISTSETTITLE � DM_LETSGETTITLE ��� ���������/���������
     ���������� DI_LISTBOX. ������������ ��������� FarListTitle.
   ! ��� ������ ����������� �������, ����� ������ �����������, �������������
     ��������� �������, � ��������� ������ �� �� ������ ����������������.
   ! ���������� ��������� � DI_LISTBOX � DI_COMBOBOX, ������ �� ����� ���� :)
     ��� ���� ������������ ���� DIF_LISTAUTOHIGHLIGHT.
  03.06.2001 SVS
   ! ��������� SelectFromEditHistory � ������ ������ ListUserData
     (���������� ��������� ���� �����, ������� ���� � ������� � ������
      � ����� ������)
   + DM_LISTGETDATA, DM_LISTSETDATA
  30.05.2001 KM
   - �������� ������������� ������� � ��������� ������� �������
     ��� ������������� DM_MOVEDIALOG � DM_RESIZEDIALOG
   + ������� � �������� DM_SETITEMPOSITION:
     Param1 = ID �������� �������.
     Param2 = ��������� �� ��������� SMALL_RECT � ������ ������������.
     ���������� TRUE ��� ������� ID, FALSE � ��������� ������.
  28.05.2001 SVS
   ! RegKey[80] -> RegKey[NM]
  27.05.2001 SVS
   ! ��� RO �������� �������������� ���� ����������� RO ���������.
   ! ��� DM_SHOWITEM ����� ������������ ������� ��� ������
  26.05.2001 OT
   - ����������� ������ ������� � NFZ
   + ���������� �������� ������� "���������������" �������
  24.05.2001 SVS
   ! ���� ������������ USeLastHistory, �� ��������� ���� � �������, �������
     ��� ��������� - � ����� �� ������...
     �.�. ���� ��������� ��� �� �������� ������ ������, �� � ��������� ���
     ������ ��������� ���� ����� � ��������� ���.
  23.05.2001 VVM
   ! ������� ��������� ���������� �� KEY_DOWN. �� ���������� ��������...
  23.05.2001 SVS
   - �������� � �������� ��������� � ���� - Part II (����, � ������ �����
     ������� :-( )
  23.05.2001 SVS
   - �������� � �������� ��������� � ����.
  21.05.2001 DJ
   + ��������� ����� ������
  21.05.2001 SVS
   + DM_SETITEMPOSITION - ������ �� ������� (����� ��� �� ������������)
   + DM_RESIZEDIALOG
   ! struct MenuData|MenuItem
     ���� Selected, Checked, Separator � Disabled ������������� � DWORD Flags
  18.05.2001 DJ
   ! Dialog ����������� �� Frame
  18.05.2001 SVS
   + DM_GETCHECK/DM_SETCHECK/DM_SET3STATE
   + DM_LISTINFO/DM_LISTFINDSTRING/DM_LISTINSERT
   ! DM_MOVEDIALOG - ���� Param1 == -1, �� Param2=COORD=ResizeDialog
  17.05.2001 SVS
   + DM_LISTUPDATE - ������ ����� ��� ��� ����� ;-(
  15.05.2001 KM
   - ������ ��������� � DI_LISTBOX ��������. ��� � ���������
     ������������ ���� DIF_LISTNOAMPERSAND (���� �������, �� ��� ���).
   ! � ����� � ���������� ������� ����� ����������� ���� DIF_LISTHIGHLIGHT.
   ! ��������� � DI_COMBOBOX ������� � �������������� DIF_LISTNOAMPERSAND.
   - ����� ��� � ���������� ��� ������� KEY_END � DI_LISTBOX.
  14.05.2001 SVS
   ! DMODE_SMALLDILAOG -> DMODE_SMALLDIALOG
   ! DIF_CENTERGROUP ������ ��� DI_BUTTON, DI_CHECKBOX, DI_RADIOBUTTON, DI_TEXT.
   - ��������� �������� � InitDialogObjects.
   - � AdjustEditPos �� ��� ����� ��� ����, ��� ListBox "�����" �
     DialogItem.ListPtr
  13.05.2001 SVS
   + DIF_LISTWRAPMODE, DIF_LISTHIGHLIGHT
   ! ��� DI_COMBOBOX&DIF_DROPDOWNLIST ������� ������� KEY_DOWN ������������
     Ctrl-Down, �.�. ������ ����������.
   ! ������� ���� DIF_CENTERGROUP ��� ����������
   - ��������� ���� � ������������ ����� �������� DMODE_SMALLDILAOG
   + ����� ��������� DM_LISTADDSTR (Param1=ID Param2=String)
   ! DI_LISTBOX ������ "����� � DialogItem.ListPtr"
  08.05.2001 SVS
    + ��������� ����� DMODE_SMALLDILAOG
  07.05.2001 SVS
    + DM_LISTSORT, DM_LISTADD, DM_LISTDELETE, DM_LISTGET, DM_LISTGETCURPOS,
      DM_LISTSETCURPOS
    ! SysLog(); -> _D(SysLog());
  07.05.2001 SVS
    ! ��� ����������� �������������� ����� ��������������� ��������� Ctrl-End
  06.05.2001 DJ
    ! �������� #include
  04.05.2001 SVS
    ! ������� �� ����� ���� �� DI_LISTBOX ;-) - ����� ���� FarDialogItem.ListPos
    - ���� � DN_INIT* - ��������� "�� ������� ����", �.�. �� �����������
      ������� ����������� �������.
    - ������ ����� �������� DialogEdit->FastShow() � ������� �������������?
  28.04.2001 SVS
   + ������� GetItemRect() ��������� ��������� �����.
   - DN_MOUSECLICK ���������� �� �������, ���� ����� ������ ������ � ������.
  27.04.2001 SVS
   - �� �������� ���������������� � ������� � � ����������� - ������
     MaxLen, ������ sizeof(MaxLen) :-((
  27.04.2001 VVM
   + ��������� KEY_MSWHEEL_XXXX
   - ����� ������� ������ ��� ���������.
  26.04.2001 SVS
   - �������� � DM_SETTEXTLENGTH: ���������� ������������ ������ � ���
     ������, ���� �� ��� �� ���������.
  25.04.2001 SVS
   + ��������� �� ������ DM_SETTEXTLENGTH & DIF_VAREDIT
  24.04.2001 SVS
   ! ������� ������ ��� ��������� ������.
   ! ���� � ����� �� ������� DN_MOUSECLICK (Param=-1) ���������� �������
     ������ TRUE, �� ������ �� ����� ������. ���� ������������
     {DN_MOUSECLICK,-1} ��� ������� FALSE, �� ������ �� ���������.
   ! ���� ����� ��� �������� - �������������� ������ ����� � ������ �������
     ��������� ������� �� ����� ��������
  23.04.2001 SVS
   - ����� ������� ����� DN_EDITCHANGE ��� ������ �� �������.
  22.04.2001 SVS
   + DIF_SHOWAMPERSAND ��� DI_BUTTON, DI_CHECKBOX, DI_RADIOBUTTON
  16.04.2001 SVS
   + Tab � ������ ������� - ������ Enter
   ! ����������� � �������������� ������ ���� ����� DN_EDITCHANGE (imho)
  12.04.2001 SVS
   + DM_ADDHISTORY - �������� ������ � �������
   + DIF_MANUALADDHISTORY - ��������� � ������� ������ "�������"
   ! ������� AddToEditHistory ������ ���������� ��������� ��������
     ���������� ������ � �������
  12.04.2001 SVS
   ! �������������� �������� ��� DM_SETDLGITEM �� ����� ���� �������.
     ������ ���� ������ - ���� ��� �� ������ � ������������. ����� ��� ����.
   + CheckDialogCoord() - �������� � ������������� ��������� �������
   ! �� ��� ���������� �������� ������������� ������� ��� DM_MOVEDIALOG
     ��� ����� ���������� = -1, � ������ ���������� ��������.
  02.04.2001 SVS
   + �������� ����� ������ RO ��� ���� ����� � ����������
  23.03.2001 SVS
   ! � ������� ConvertItem() ����� �������� InternalCall - ������
     ������������ ������ ��� DN_EDITCHANGE
  22.03.2001 SVS
   - ������� ���������� ��������� DN_EDITCHANGE
  05.03.2001 SVS
   - ���� � ������� :-(
  21.02.2001 IS
   ! Opt.EditorPersistentBlocks -> Opt.EdOpt.PersistentBlocks
  21.02.2001 IS
   - ��������� �� ������ ������ � SelectFromEditHistory (����������� �� � ����,
     �� ����������� ��!)
  20.02.2001 SVS
   ! ��������� ��������� IsKeyHighlighted � ��������� Alt- ��
     ������� ��� ��������
  20.02.2001 SVS
   ! ��������� ��������� ������� ������ � ������ Disabled & Hidden...
  20.02.2001 SVS
   - ���� � SelectFromComboBox
  13.02.2001 SVS
   ! HISTORY_COUNT - ��������� ��� ������� �������.
   + �������������� �������� � FindInEditForAC, SelectFromEditHistory,
     AddToEditHistory � SelectFromComboBox - MaxLen - ������������ ������
     ������ ����������.
   + DI_COMBOBOX ���� ����� �������� � DIF_VAREDIT
   ! ��������� "�������" ���������� � DefDlgProc(DN_DRAWDIALOG,1)
   ! ���� ������� ���������� � ����� �� DN_DRAWDIALOG ������� FALSE,
     �� ������ �������������� �� �����
   ! ���� ������� ���������� � ����� �� DN_DRAWDLGITEM ������� FALSE,
     �� ������� ������� �������������� �� �����
  12.02.2001 SVS
   + ������� �� ������� DOUBLE_CLICK - �������� ����� ������� ������������� :-)
     AN> ...�������� �� �� �������� ������������� ����� ������.
     AN> ��� ������ ���������� ������� �� (MouseEvent.dwEventFlags==DOUBLE_CLICK).
  11.02.2001 SVS
   ! DIF_VAREDIT - ������ ��� DI_EDIT!!!
  11.02.2001 SVS
   ! ��������� ��������� ���� � ����� � ����������� � ��������� MenuItem
  23.01.2001 SVS
   ! �������� ������� DeleteDialogObjects() � GetDialogObjectsData()
   + ������� ��������� � DataToItem � ConvertItem
   ! ������� �������� �� NULL �������� ObjPtr
  04.01.2001 SVS
   - Bug - DM_KEY �� ���������� �� ��, ��� ���������� ���������������� �������
  04.01.2001 SVS
   - Bug ��� ������������� DM_SETDLGITEM - ������� �������������� ����� �����
  28.12.2000 SVS
   + ��������� ��������� Opt.HotkeyRules
  25.12.2000 SVS
   - ����� ������� ������� �� ������� ��� DM_GETTEXTPTR
  21.12.2000 SVS
   ! Ctr-Break ������ ��������������, �.�. ��� ������� �� ����
     ��� ������ ����������.
   + DIF_SHOWAMPERSAND ��� DI_*BOX
   + DM_GETTEXTPTR, DM_SETTEXTPTR
  15.12.2000 SVS
   ! ��� ����������� ������� ��������� ��������� "�����������" ����.
   ! ����� ������ �������� �����������
  14.12.2000 SVS
   ! ���������� ������ (��������� :-)
   + ������ ������� ������� ��� DIF_DISABLE
  08.12.2000 SVS
   ! DM_SET(GET)TEXT - Param2 ��������� �� ��������� FarDialogItemData
  06.12.2000 SVS
   - ���������� ���� � SelectOnEntry() - ��� ������� ����������
     �� �������� ���������!!!
   ! ��������� �������� ���� ��� ������� �������� � DefDlgProc
   ! ������� ������ ������:
     1) DI_BUTTON: ���� �� ������ ����� � ������ "�� ��� ��������"
                   (DIF_BTNNOCLOSE), �� ������ �� ������, ����� -
                   ���������� ������� ������.
     2) ���� ������ Enter �� �� DI_BUTTON, �� ������������ ��� � ������
        ��� �������, ��� ���� ������ � Default=1 � � ���� ������ ��
        ��������� ���� DIF_BTNNOCLOSE.
  05.12.2000 IS
   ! ��� ������ � �����, ��� ���������, ������������� ��� ���,
     � ������� ������
  04.12.2000 SVS
   - ������� � DIF_NOFOCUS :-(
   - ��� �������� � ���������� ����� - ��������� ������ ������ :-(
   ! ��� DI_USERCONTROL - ��� ����������� Data ������������ memmove()
  04.12.2000 SVS
   ! �������� � ������� �����:
     "Ctrl-A Alt-N Enter - ����� ����� �� �������������� � ���� ����."
   ! �������������� - ����� �� �������� �� ����� ������������ ��������.
   ! ����������� ������� ConvertItem() � DataToItem() - � �����������
     ����� ���������� ���������� � ������� ��� (MSVC - ��� ��� ������ :-(
   + DIF_3STATE - 3-� ��������� CheckBox
   ! ������� �� ��� ������ ���� DIF_DROPDOWNLIST - ������ ��� DI_COMBOBOX.
   - ��������� �� ������ ����������� � ���� ����������� ��������
   ! ��� DI_PSWEDIT � DI_FIXEDIT ��������� DIF_EDITEXPAND �� �����
   ! ��������� Disabled
  03.12.2000 IS
   ! �� �������������, ���� ����� ������� ���� ������������ �������.
     �������� ��� �������, �����������, ������ � ����������� �������.
  21.11.2000 SVS
   - �� ��������� ��������� ������ � ������������� ���������
  08.11.2000 SVS
   ! ������� �������� ����� ������� ��� hotkey (������������ ��������)
  04.11.2000 SVS
   + �������� �� �������������� ������� ��� XLat-�������������
  26.10.2000 SVS
   ! DM_SETEDITPOS/DM_GETEDITPOS -> DM_SETCURSORPOS/DM_GETCURSORPOS
   + ������ � �������� ��� DI_USERCONTROL � ������������ ��������.
  23.10.2000 SVS
   + DM_SETEDITPOS, DM_GETEDITPOS -
      ���������������� ������� � ������� ��������������.
  20.10.2000 SVS
   + DM_GETFOCUS - �������� ID �������� �������� ����� �����
  16.10.2000 tran 1.47
   + ��� EDIT ����� ������������ ����������� � 511 ��������
  27.09.2000 SVS
   ! Alt-Up/Down/Left/Right - ����� (����� � ������� �� ������������
     � MultiEdit)
   ! Ctrl-Alt-Shift - ���������, ���� ����.
  24.09.2000 SVS
   + �������� ������� - Alt-�������
   + ����� ������� Xlat
  22.09.2000 SVS
   ! ��������� AutoComplete ��� ���������� ������.
  20.09.2000 SVS
   ! Enter � ������� ����� (����� DIF_EDITOR) ��������� ������.
  18.09.2000 SVS
   + DIF_READONLY - ���� ��� ����� ��������������
      (����! ��� ����� ��������������).
  18.09.2000 SVS
   ! ��������� ��� SelectOnEntry
   ! ����� �� ������ ���� ������ (������ �� �������� �� �����������)!
  14.09.2000 SVS
   + ���� DIF_LISTNOAMPERSAND. �� ��������� ��� DI_LISTBOX
      ������������ ���� MENU_SHOWAMPERSAND. ���� ���� ��������� �����
      ���������
  12.09.2000 SVS
   ! ������ ��������� ��� ������ � DefaultButton=1:
     ����� ������ ���������� �� ����� ������� ���������� ��������� DM_CLOSE.
   ! ���������� �������� � BackSpace � DIF_EDITOR
   ! ������ ��������, ���� Del ������ � ������� �������, ��� �����
     ������ (DIF_EDITOR)
  11.09.2000 SVS
   + Ctrl-U � ������� ����� ������� ������� �����
  09.09.2000 SVS
   + DIF_NOFOCUS - ������� �� �������� ������ ����� (�����������)
   + ����� ������� DMODE_OLDSTYLE - ������ � ������ �����.
   ! �������� �� �������, ����� ��� �������, ������ ������ � ������ �����.
   + ������� SelectOnEntry - ��������� ������ ��������������
     (��������� ����� DIF_SELECTONENTRY)
  08.09.2000 SVS
   - ���� �������, �� DM_SETFOCUS ����� ��� � ������� :-)
   ! ��������� ��� DN_MOUSECLICK
  31.08.2000 SVS
   + DM_ENABLE (�� ��������� ����� :-)
   - ���� � ������� ������ ������.
  30.08.2000 SVS
   + ����� Hide()
   + ����� ������� DMODE_SHOW - ������ �����?
   ! ��������� ��� IsEnableRedraw
   + DM_MOVEDIALOG - ����������� �������.
   ! ��������� ������ ��� ComboBox(DowpDownList)
  29.08.2000 SVS
   ! ��� ������� ���� ������ �� �������� ���������...
     ������, ����� ����� ����������� �������!
  29.08.2000 SVS
   - ������ ����������� �����-��� - ������� ProcessHighlighting
     MY> ������ � ��������� ����� �������. � ���� � ���� ������� �������.
     MY> ������ � ��������� ���� ������, ���� Alt-������ ����� �
     MY> ��������� ������������� �����.
  28.08.2000 SVS
   - ��� ��� ������ (��� �� ��������������!) :-)
  25.08.2000 SVS
   + DM_GETDLGRECT - �������� ���������� ����������� ����
   ! ��������� ��� DN_MOUSECLICK
  25.08.2000 SVS
   ! ���������, ������������ ������ ����� - �� �� ��� ��������, ����.
  24.08.2000 SVS
   + InitDialogObjects ����� �������� - ��� ���������� ���������������
     ���������
  24.08.2000 SVS
   ! ���������� ����!!!! (������ ������ �����)... ��� ��� ComboBox
     ����� ����� �� �����...
   + CtrlAltShift - ��������/�������� ������...
   + ������� DI_USERCONTROL - ���������� ���������� ������.
  24.08.2000 SVS
   ! ����������� ������ - � ������� �� �������...
     ������������ � ChangeFocus()
  23.08.2000 SVS
   ! ��������� ��������� DMSG_* -> DM_ (�����) & DN_ (������)
   + DM_KEY        - �������/�������� �������(�)
   + DM_GETDLGDATA - ����� ������ �������.
   + DM_SETDLGDATA - ���������� ������ �������.
   + DM_SHOWDIALOG - ��������/�������� ������
   + ���������� ������ FocusPos - ������ �������� ����� ������� � ������
   ! ���������� IsCanMove, InitObjects, CreateObjects, WarningStyle, Dragged
     ������� -> ������� ����� � DialogMode
   + ��������� ������ ��������� ;-)
  22.08.2000 SVS
   ! � ���� ���������� ������ �� ��� :-((
     IsMovedDialog -> IsCanMove
   ! DMSG_PAINT -> DMSG_DRAWDIALOG
   ! DMSG_DRAWITEM -> DMSG_DRAWDLGITEM
   ! DMSG_CHANGELIST -> DMSG_LISTCHANGE
   ! ShowDialog - �������������� �������� - ����� ������� ������������
  21.08.2000 SVS 1.23
   ! �������� ��������� ������ - �������� � ����� :-)))
   ! ������ ���������� � ���� ����� ������ ���� DefDlgProc � SendDlgMessage
     (��� ��� ������ :-)
   + ����� ���������� DI_LISTBOX ������� �� ��������� �������� ���������
   ! DIF_HISTORY ����� ����� ������� ���������, ��� DIF_MASKEDIT
   - ���� � AutoComplete ��� ���������� ���������� ������
   ! DMSG_CHANGEITEM -> DMSG_EDITCHANGE
   + DMSG_BTNCLICK
  12.08.2000 KM 1.20
   + ���������� ������ DI_FIXEDIT � ������ DIF_MASKEDIT ��� ���������
     ����� � ������ �����.
  18.08.2000 SVS
   + DialogMode - ����� �������� ������ �������
   + ���� IsEnableRedraw - �����������/����������� ����������� �������
   + ���������: DMSG_ENABLEREDRAW, DMSG_MOUSECLICK
   + DI_BUTTON ���� ������ ����� ����� DIF_SETCOLOR
   + ���� ��� DI_BUTTON - DIF_BTNNOCLOSE - "������ �� ��� �������� �������"
   - ���� �� ����� ��������� �������� "���", �� ������ ������������, �.�.
     �� ��� ������� ���� ������.
  15.08.2000 SVS
   ! ��� DropDownList ����� ������������ �� �����.
   + ������� ���, ����� ����� ������ � DropDownList ������ ����������� ���.
  11.08.2000 SVS
   + ������, ������������� ��� ����������� ���������� �������
   + ��� ����, ����� ������� DMSG_CLOSE ����� �������������� Process
   ! ��������� ��� DMSG_CLOSE
  11.08.2000 KM 1.18
   ! ����� ����������� ���, ������������ ������������ ����������� �������
     ������. ����������� �� � ������� ������� ������ � ���� ���� :)
   ! ����-���� ���������� �������� ������ �������. ����: ����� ������� �������
     ������ �� ������� ����������� ������ ����������� �� ���������� �� ��� ���
     ���� �� ���������� ���� �������� �������, ����� ���� � �����������
     ����������� ������ ����� ������, ��� ���� � ����� ������������� ������� :)
   ! ��������: ���� ����� ������� ������� ����, �� �������� ����
     ������ ����� ������, ����� ����������� ������ (������ ��������� ��� �����),
     �� ��-�� ����, ��� � ����� ������� PrevMouseX � PrevMouseY ��� �� ����������,
     ����� ������������� ��������� ������ �������.
  10.08.2000 SVS
   + ���������� IsMovedDialog - ����� �� ������� ������ :-)
   + ������� ��������� IsMovedDialog
  09.08.2000 tran 1.16
   - ������ "�������"
  09.08.2000 KM
   ! ��� ��������� ������ ����������� ������� ���������
     ���������� ��������� �������. ��� ���������.
   ! ���������� ����������� ������� ������, ������-�� �� �������
     ���������� :). ������ ����������� ����� ����������, ��� ������������
     ������� �� ������.
   ! ��� ������ �� ���� ������ ��������, ����, �� �����������, ����������
     ����������.

     ����� �������� ������� ������� - ����� ����
     ��������� �����.
  07.08.2000 SVS
   + � ������� ������������ ��������� ��� ListBox ������!
  04.08.2000 SVS
    + FarListItems.CountItems -> FarListItems.ItemsNumber
  03.08.2000 tran
   + ������� �������� ������� - �������� �� ������ �����
     �������� - ����������� �������� �� ������� ������ ��������� �� ���
     ����� ������ �����...
     �������� ��������� - �� ����� ������� �����
     � MOVE � ���� ����� ���� ����� � �����������.
     ������ ��� MOVE ������������� "//# "
  01.08.2000 SVS
   ! History ������ ������ ����� ScrollBar, �.�. ���� ������� �����
     � ComboBox`�, ������ � ����.
   - ���������� ������ lastKey ������� �� ������������� :-)
   + ������� ListBox
   - ��������� ������ � AutoComplete
   ! � History ������ ��������� �������� (��� DIF_EXPAND...) �����
     ����������� �����!
   + ��� �� ����� ���� DIF_USELASTHISTORY � �������� ������ �����,
     �� ��������������� ������ �������� �� History
   - ��������� ����������� ��� DI_PSWEDIT ����� History...
     ...��� �� ������ �������... � ��� ��������� ������, �.�.
  31.07.2000 tran & SVS
   + ����������� ������� �� ������ ���������. Ctrl-F5 �������� �����
     �����������. ��������� ����������� - "Move" � ����� ������� ����
  28.07.2000 SVS
   ! �������� Edit *EditLine � ������� FindInEditForAC ����� �������!
   - ��������� ��� � ���������������:
       ...���� � ������� �� F7 - "templates". ��� F7, ������� shift+t=T � ...
       ������� ��������� t. � ����� ������� ������� ������ ���������� �
       ����� ��������� � ��������� ����...
   - ���� ������ �� �������� �� ������ ��������� � �������,
     �� �������� ������ �� ���� ������������, � ���������
     ����� �� ������ �������������� �������� ;-)
   + AutoComplite: ��� DI_COMBOBOX.
   ! SelectFromComboBox ����� �������������� �������� � ���, �����
     ��������������� item � ���� �� ������� � ����������� �� ������� �����
   ! FindInEditHistory -> FindInEditForAC
     ����� ��� � �������, ��� � � ComboBox`� (����� �� ������� ����)
   + ������� IsFocused, ������������ - "����� �� ������� �������
     ����� ����� �����"
   + ������� ConvertItem - �������������� �� ����������� �������������
     � FarDialogItem � �������
   + ��������� ���������� ���������:
        DMSG_INITDIALOG, DMSG_ENTERIDLE, DMSG_HELP, DMSG_PAINT,
        DMSG_SETREDRAW, DMSG_DRAWITEM, DMSG_GETDLGITEM, DMSG_KILLFOCUS,
        DMSG_GOTFOCUS, DMSG_SETFOCUS, DMSG_GETTEXTLENGTH, DMSG_GETTEXT,
        DMSG_CTLCOLORDIALOG, DMSG_CTLCOLORDLGITEM, DMSG_CTLCOLORDLGLIST,
        DMSG_SETTEXTLENGTH, DMSG_SETTEXT, DMSG_CHANGEITEM, DMSG_HOTKEY,
        DMSG_CLOSE,
  26.07.2000 SVS
   + �� �������-�� - ������������ ��������������� ComboBox
  26.07.2000 SVS
   + AutoComplite: ��� DIF_HISTORY.
  25.07.2000 SVS
   + ����� �������� � ������������
  23.07.2000 SVS
   + ���� ������� � ���������� :-)
   + ������� ����� ����������� - ������� � ���� ������� ���������
   ! ��������� ��������� "SavedDialogHistory\\%s",
     "Locked%d" � "Line%d" ������� ��������������.
   + ������� ��������� ������� (�� ���������) DefDlgProc() - ������ ����� :-)
  19.07.2000 SVS
   ! "...� ��������� ������ ���� ������� home shift+end del
     ���� �� ���������..."
     DEL � ������, ������� DIF_EDITOR, ������� ��� ����� ���������...
  18.07.2000 SVS
   + ��������� �������� DI_COMBOBOX (���� ��� ��� ��������������)
   + �������-���������� ������ �� ������ - SelectFromComboBox
  11.07.2000 SVS
   ! ��������� ��� ����������� ���������� ��� BC & VC
  05.07.2000 SVS
   + ��������� �������� �� ���� DIF_EDITEXPAND - ���������� ����������
     ����� � �������� ������� DI_EDIT
  25.06.2000 SVS
   ! ���������� Master Copy
   ! ��������� � �������� ���������������� ������
*/

#include "headers.hpp"
#pragma hdrstop

#include "farconst.hpp"
#include "dialog.hpp"
#include "lang.hpp"
#include "fn.hpp"
#include "global.hpp"
#include "keys.hpp"
#include "ctrlobj.hpp"
#include "chgprior.hpp"
#include "vmenu.hpp"
#include "edit.hpp"
#include "help.hpp"
#include "scrbuf.hpp"
#include "manager.hpp"
#include "savescr.hpp"

static char HisLocked[16]="Locked", *PHisLocked=NULL;
static char HisLine[16]  ="Line", *PHisLine=NULL;
static char fmtSavedDialogHistory[]="SavedDialogHistory\\%s";

//////////////////////////////////////////////////////////////////////////
/* Public:
   ����������� ������ Dialog
*/
Dialog::Dialog(struct DialogItem *Item,    // ����� ��������� �������
               int ItemCount,              // ���������� ���������
               FARWINDOWPROC DlgProc,      // ���������� ���������
               long InitParam)             // �������������� � �������� ������
{
  _tran(SysLog("[%p] Dialog::Dialog()",this));

  if(!PHisLocked) // ���� ��������� �������� �� ���������������� - ������� ��� ������
  {
    PHisLocked=HisLocked+strlen(HisLocked);
    PHisLine=HisLine+strlen(HisLine);
  }
  SetDynamicallyBorn(FALSE); // $OT: �� ��������� ��� ������� ��������� ����������
  /* $ 17.05.2001 DJ */
  CanLoseFocus = FALSE;
  HelpTopic = NULL;
  /* DJ $ */
  /* $ 19.05.2001 DJ */
  OwnsItems = FALSE;
  /* DJ $ */
  /* $ 29.08.2000 SVS
    ����� �������, ���������� ������ (-1 = Main)
  */
  PluginNumber=-1;
  /* SVS $ */
  /* $ 11.08.2000 SVS
    + ������, ������������� ��� ����������� ���������� �������
  */
  Dialog::DataDialog=InitParam;
  /* SVS $ */
  DialogTooLong=0;
  /* $ 10.08.2000 SVS
     ���������� ������� ����� �������
  */
  DialogMode.Set(DMODE_ISCANMOVE);
  /* SVS $ */
  /* $ 23.06.2001 KM */
  SetDropDownOpened(FALSE);
  /* KM $ */
  /* $ 18.08.2000 SVS
  */
  /*
    + ���� IsEnableRedraw - �����������/����������� ����������� �������
      =0 - ���������, ������ �������� - �� ��������������
        ����� ���������� ��������� DMSG_ENABLEREDRAW, �� ���� ����
        ��� Param1=TRUE �������������, ��� Param1 = FALSE - �����������
  */
  IsEnableRedraw=0;

  FocusPos=-1;
  PrevFocusPos=-1;

  if(!DlgProc) // ������� ������ ���� ������!!!
  {
    DlgProc=(FARWINDOWPROC)Dialog::DefDlgProc;
    // ����� ������ � ������ ����� - ����� ���� ����!
    DialogMode.Set(DMODE_OLDSTYLE);
  }
  Dialog::DlgProc=DlgProc;

  Dialog::Item=Item;
  Dialog::ItemCount=ItemCount;

  if (CtrlObject!=NULL)
  {
    // �������� ����. ����� �����.
    PrevMacroMode=CtrlObject->Macro.GetMode();
    // ��������� ����� � �������� :-)
    CtrlObject->Macro.SetMode(MACRO_DIALOG);
  }
//_SVS(SysLog("Dialog =%d",CtrlObject->Macro.GetMode()));

  // ���������� ���������� ��������� �������
  GetConsoleTitle(OldConsoleTitle,sizeof(OldConsoleTitle));
}


//////////////////////////////////////////////////////////////////////////
/* Public, Virtual:
   ���������� ������ Dialog
*/
Dialog::~Dialog()
{
  _tran(SysLog("[%p] Dialog::~Dialog()",this));
  INPUT_RECORD rec;

  GetDialogObjectsData();
  DeleteDialogObjects();

  if (CtrlObject!=NULL)
    CtrlObject->Macro.SetMode(PrevMacroMode);

  Hide();
  ScrBuf.Flush();

  /* $ 17.05.2001 DJ */
  if (HelpTopic)
    delete [] HelpTopic;
  /* DJ $ */

  /* $ 19.05.2001 DJ
     ���� �� ������� ��������, ������� ��
  */
  if (OwnsItems)
    delete [] Item;
  /* DJ $ */

  PeekInputRecord(&rec);
  SetConsoleTitle(OldConsoleTitle);
}

void Dialog::CheckDialogCoord(void)
{
  if (X1 == -1) // ������ ������������� ������� �� �����������?
  {             //   X2 ��� ���� = ������ �������.
    X1=(ScrX - X2 + 1)/2;

    if (X1 <= 0) // ������ ������� ������ ������ ������?
    {
      DialogTooLong=X2-1;
      X1=0;
      X2=ScrX;
    }
    else
      X2+=X1-1;
  }

  if (Y1 == -1) // ������ ������������� ������� �� ���������?
  {             //   Y2 ��� ���� = ������ �������.
    Y1=(ScrY - Y2 + 1)/2;

    if (Y1>1)
      Y1--;

    if(!DialogMode.Check(DMODE_SMALLDIALOG)) //????
      if (Y1>5)
        Y1--;

    if (Y1<0)
    {
       Y1=0;
       Y2=ScrY;
    }
    else
      Y2+=Y1-1;
  }
}

//////////////////////////////////////////////////////////////////////////
/* Public, Virtual:
   ������ �������� ��������� ���� ������� � ����� �������
   ScreenObject::Show() ��� ������ ������� �� �����.
*/
void Dialog::Show()
{
  _tran(SysLog("[%p] Dialog::Show()",this));

  if(PreRedrawFunc)
     PreRedrawFunc();

  if (!DialogMode.Check(DMODE_INITOBJECTS))      // ��������������� �������, �����
  {                      //  �������� ���������������� ��� ������ ������.
    /* $ 28.07.2000 SVS
       ������ ���������, ��� � ��� ��� ��!
    */
    CheckDialogCoord();
    if(DlgProc((HANDLE)this,DN_INITDIALOG,InitDialogObjects(),DataDialog))
    {
      // ��� �����, �.�. ������ ����� ���� ��������
      InitDialogObjects();
    }
    SetFarTitle(GetDialogTitle());
    // ��� ������� �������������������!
    DialogMode.Set(DMODE_INITOBJECTS);
  }
  CheckDialogCoord();
  DialogMode.Set(DMODE_SHOW);
  ScreenObject::Show();
}

/* $ 30.08.2000 SVS
  ���� ��������� ������ ������� - ���������� ����������...
*/
void Dialog::Hide()
{
  _tran(SysLog("[%p] Dialog::Hide()",this));
  DialogMode.Skip(DMODE_SHOW);
  ScreenObject::Hide();
}
/* SVS $*/

//////////////////////////////////////////////////////////////////////////
/* Private, Virtual:
   ������������� �������� � ����� ������� �� �����.
*/
void Dialog::DisplayObject()
{
  if(DialogMode.Check(DMODE_SHOW))
  {
    ChangePriority ChPriority(THREAD_PRIORITY_NORMAL);
    if(!DialogMode.Check(DMODE_SMALLDIALOG))
      Shadow();              // "�������" ����
    ShowDialog();          // "��������" ������.
  }
}


//////////////////////////////////////////////////////////////////////////
/* Public:
   ������������� ��������� �������.
*/
/* $ 28.07.2000 SVS
   ������ InitDialogObjects ���������� ID ��������
   � ������� �����
*/
/* $ 24.08.2000 SVS
  InitDialogObjects ����� �������� - ��� ���������� ���������������
  ���������. ID = -1 - ������� ���� ��������
*/
int Dialog::InitDialogObjects(int ID)
{
  int I, J;
  int Length,StartX;
  int Type;
  struct DialogItem *CurItem;
  int InitItemCount;
  DWORD ItemFlags;

  if(ID+1 > ItemCount)
    return -1;

  if(ID == -1) // �������������� ���?
  {
    ID=0;
    InitItemCount=ItemCount;
  }
  else
  {
    InitItemCount=ID+1;
  }

  /* 04.01.2001 SVS
     ���� FocusPos � �������� � ������� ����������, �� ���� �������. */
  if(FocusPos >= 0 && FocusPos < ItemCount &&
     (Item[FocusPos].Flags&(DIF_DISABLE|DIF_NOFOCUS|DIF_HIDDEN)))
    FocusPos = -1; // ����� ������ �������!
  /* SVS $ */

  // ��������������� ���� �� ������ ������
  for(I=ID; I < InitItemCount; I++)
  {
    CurItem=&Item[I];
    ItemFlags=CurItem->Flags;
    Type=CurItem->Type;

    // ��� ������ �� ������ ����� "���������� ��������� ������ ��� ������"
    //  ������� ���� ����� ������
    if (Type==DI_BUTTON &&
        (ItemFlags & DIF_NOBRACKETS)==0 &&
        *CurItem->Data != '[')
    {
      char BracketedTitle[200];
      sprintf(BracketedTitle,"[ %s ]",CurItem->Data);
      strcpy(CurItem->Data,BracketedTitle);
    }

     // ��������������� ���� ������
     if(FocusPos == -1 &&
        IsFocused(Type) &&
        CurItem->Focus &&
        !(ItemFlags&(DIF_DISABLE|DIF_NOFOCUS|DIF_HIDDEN)))
       FocusPos=I; // �������� ������ �������� �������
     CurItem->Focus=0; // ������� ��� ����, ����� �� ���������,
                       //   ��� ������� - ��� � ������� ��������

     // ������� ���� DIF_CENTERGROUP ��� ����������
     switch(Type)
     {
       case DI_BUTTON:
       case DI_CHECKBOX:
       case DI_RADIOBUTTON:
       case DI_TEXT:
         break;
       default:
         if(ItemFlags&DIF_CENTERGROUP)
           CurItem->Flags&=~DIF_CENTERGROUP;
     }
  }

  // ����� ��� ����� ����� - ������, ���� "����" ������ ���������
  // ���� �� ����, �� ������ �� ������ ����������
  if(FocusPos == -1)
  {
    for (I=0; I < ItemCount; I++) // �� ����!!!!
    {
      CurItem=&Item[I];
      if(IsFocused(CurItem->Type) &&
         !(CurItem->Flags&(DIF_DISABLE|DIF_NOFOCUS|DIF_HIDDEN)))
      {
        FocusPos=I;
        break;
      }
    }
  }
  if(FocusPos == -1) // �� �� ����� ���� - ��� �� ������
  {                  //   �������� � ������������ ������
     FocusPos=0;     // ������, ����
  }

  // �� ��� � ��������� ��!
  Item[FocusPos].Focus=1;

  // � ������ ��� ������� � �� ������ ���������...
  for (I=ID; I < InitItemCount; I++)
  {
    CurItem=&Item[I];
    Type=CurItem->Type;
    ItemFlags=CurItem->Flags;

    // ��������������� ����������� �������� � ������ DIF_CENTERGROUP
    // � ���������� ������������ �������� ����� �������������� � �������.
    // �� ���������� X �� �����. ������ ������������ ��� �������������
    // ����� ������.
    if ((ItemFlags & DIF_CENTERGROUP) &&
        (I==0 ||
          (I > 0 &&
            ((Item[I-1].Flags & DIF_CENTERGROUP)==0 ||
             Item[I-1].Y1!=CurItem->Y1)
          )
        )
       )
    {
      Length=0;

      for (J=I; J < ItemCount &&
                (Item[J].Flags & DIF_CENTERGROUP) &&
                Item[J].Y1==Item[I].Y1; J++)
      {
        Length+=HiStrlen(Item[J].Data);

        if (Item[J].Type==DI_BUTTON && *Item[J].Data!=' ')
          Length+=2;
      }

      if (Item[I].Type==DI_BUTTON && *Item[I].Data!=' ')
        Length-=2;

      StartX=(X2-X1+1-Length)/2;

      if (StartX<0)
        StartX=0;

      for (J=I; J < ItemCount &&
                (Item[J].Flags & DIF_CENTERGROUP) &&
                Item[J].Y1==Item[I].Y1; J++)
      {
        Item[J].X1=StartX;
        StartX+=HiStrlen(Item[J].Data);

        if (Item[J].Type==DI_BUTTON && *Item[J].Data!=' ')
          StartX+=2;
      }
    }
    /* $ 01.08.2000 SVS
       ������� ListBox
    */
    if (Type==DI_LISTBOX)
    {
      if (!DialogMode.Check(DMODE_CREATEOBJECTS))
        CurItem->ListPtr=new VMenu(NULL,NULL,0,CurItem->Y2-CurItem->Y1+1,
                        VMENU_ALWAYSSCROLLBAR|VMENU_LISTBOX,NULL/*,this*/);
       if(CurItem->ListPtr)
       {
         /* $ 13.09.2000 SVS
            + ���� DIF_LISTNOAMPERSAND. �� ��������� ��� DI_LISTBOX &
              DI_COMBOBOX ������������ ���� MENU_SHOWAMPERSAND. ���� ����
              ��������� ����� ���������
         */
         /* $ 15.05.2001 KM
            ! ���������� ��������� � DI_LISTBOX
         */
         /* $ 03.06.2001 KM
            ! ���������� ��������� � DI_LISTBOX, ������ �� ����� ���� :)
              ��� ���� ������������ ���� DIF_LISTAUTOHIGHLIGHT.
         */
         if(!(ItemFlags&DIF_LISTNOAMPERSAND))
           CurItem->ListPtr->SetFlags(VMENU_SHOWAMPERSAND);
         if(ItemFlags&DIF_LISTNOBOX)
           CurItem->ListPtr->SetFlags(VMENU_SHOWNOBOX);
         if(ItemFlags&DIF_LISTWRAPMODE)
           CurItem->ListPtr->SetFlags(VMENU_WRAPMODE);
         if(ItemFlags&DIF_LISTAUTOHIGHLIGHT)
           CurItem->ListPtr->AssignHighlights(FALSE);
         CurItem->ListPtr->SetPosition(X1+CurItem->X1,Y1+CurItem->Y1,
                              X1+CurItem->X2,Y1+CurItem->Y2);
         CurItem->ListPtr->SetBoxType(SHORT_SINGLE_BOX);
         // ������ ��� �����
         //ListBox->DeleteItems(); //???? � ���� �� ????
         if(CurItem->ListItems && !DialogMode.Check(DMODE_CREATEOBJECTS))
           CurItem->ListPtr->AddItem(CurItem->ListItems);
         /* KM $ */
         /* KM $ */
       }
    }
    /* SVS $*/
    // "���������" - �������� ������...
    if (IsEdit(Type))
    {
      if (!DialogMode.Check(DMODE_CREATEOBJECTS))
      {
        CurItem->ObjPtr=new Edit;
        if(Type == DI_COMBOBOX)
          CurItem->ListPtr=new VMenu("",NULL,0,8,VMENU_ALWAYSSCROLLBAR,NULL/*,Parent*/);
      }

      Edit *DialogEdit=(Edit *)CurItem->ObjPtr;
      DialogEdit->SetDialogParent(TRUE);
      /* $ 26.07.2000 SVS
         �� �������-�� - ������������ ��������������� ComboBox
      */
      /* $ 30.11.200 SVS
         ������� �� ��� ������ ���� DIF_DROPDOWNLIST
      */
      if (Type == DI_COMBOBOX)
      {
        CurItem->ListPtr->SetBoxType(SHORT_SINGLE_BOX);
        if(ItemFlags & DIF_DROPDOWNLIST)
           DialogEdit->DropDownBox=1;
        if(ItemFlags&DIF_LISTWRAPMODE)
          CurItem->ListPtr->SetFlags(VMENU_WRAPMODE);
        /* $ 15.05.2001 KM
           ������� ��������� � DI_COMBOBOX
        */
        /* $ 03.06.2001 KM
           ! ���������� ��������� � DI_COMBOBOX, ������ �� ����� ���� :)
             ��� ���� ������������ ���� DIF_LISTAUTOHIGHLIGHT.
        */
        if(!(ItemFlags&DIF_LISTNOAMPERSAND))
          CurItem->ListPtr->SetFlags(VMENU_SHOWAMPERSAND);
        if(ItemFlags&DIF_LISTAUTOHIGHLIGHT)
          CurItem->ListPtr->AssignHighlights(FALSE);
        /* $ 12.06.2001 KM
           ! �����-�� ���� ������ ������������� DI_COMBOBOX ����� FarDialogItem
              �������������!!!
        */
        if(CurItem->ListItems && !DialogMode.Check(DMODE_CREATEOBJECTS))
          CurItem->ListPtr->AddItem(CurItem->ListItems);
        /* KM $ */
        /* KM $ */
        /* KM $ */
      }

      /* SVS $ */
      /* SVS $ */
      /* $ 15.10.2000 tran
        ������ ���������������� ������ ����� �������� � 511 �������� */
      // ���������� ������������ ������ � ��� ������, ���� �� ��� �� ���������
      if(DialogEdit->GetMaxLength() == -1)
      {
        if((CurItem->Type==DI_EDIT || CurItem->Type==DI_COMBOBOX) &&
           (ItemFlags&DIF_VAREDIT))
          DialogEdit->SetMaxLength(CurItem->Ptr.PtrLength);
        else
          DialogEdit->SetMaxLength(511);
      }
      /* tran $ */
      DialogEdit->SetPosition(X1+CurItem->X1,Y1+CurItem->Y1,
                              X1+CurItem->X2,Y1+CurItem->Y2);
//      DialogEdit->SetObjectColor(
//         FarColorToReal(DialogMode.Check(DMODE_WARNINGSTYLE) ?
//             ((ItemFlags&DIF_DISABLE)?COL_WARNDIALOGEDITDISABLED:COL_WARNDIALOGEDIT):
//             ((ItemFlags&DIF_DISABLE)?COL_DIALOGEDITDISABLED:COL_DIALOGEDIT)),
//         FarColorToReal((ItemFlags&DIF_DISABLE)?COL_DIALOGEDITDISABLED:COL_DIALOGEDITSELECTED));
      if (CurItem->Type==DI_PSWEDIT)
      {
        DialogEdit->SetPasswordMode(TRUE);
        /* $ 01.08.2000 SVS
          ...��� �� ������ �������... � ��� ��������� ������, �.�.
        */
        ItemFlags&=~DIF_HISTORY;
        /* SVS $ */
      }

      if (Type==DI_FIXEDIT)
      {
        /* $ 21.08.2000 SVS
           DIF_HISTORY ����� ����� ������� ���������, ��� DIF_MASKEDIT
        */
        if(ItemFlags&DIF_HISTORY)
          ItemFlags&=~DIF_MASKEDIT;
        /* SVS $ */
        // ���� DI_FIXEDIT, �� ������ ����� �������� �� ������...
        //   ��-�� - ���� ������������������ :-)
        DialogEdit->SetMaxLength(CurItem->X2-CurItem->X1+1);
        DialogEdit->SetOvertypeMode(TRUE);
        /* $ 12.08.2000 KM
           ���� ��� ������ ����� DI_FIXEDIT � ���������� ���� DIF_MASKEDIT
           � �������� �������� CurItem->Mask, �� �������� ����� �������
           ��� ��������� ����� � ������ Edit.
        */
        /* $ 18.09.2000 SVS
          ����� �� ������ ���� ������ (������ �� �������� �� �����������)!
        */
        if ((ItemFlags & DIF_MASKEDIT) && CurItem->Mask)
        {
          char *Ptr=CurItem->Mask;
          while(*Ptr && *Ptr == ' ') ++Ptr;
          if(*Ptr)
            DialogEdit->SetInputMask(CurItem->Mask);
          else
          {
            CurItem->Mask=NULL;
            ItemFlags&=~DIF_MASKEDIT;
          }
        }
        /* SVS $ */
        /* KM $ */
      }
      else
        // "����-��������"
        // ��������������� ������������ ���� ����� (edit controls),
        // ������� ���� ���� ������������ � �������� � ������������
        // ������� � �������� �����
        if (!(ItemFlags & DIF_EDITOR))
        {
          DialogEdit->SetEditBeyondEnd(FALSE);
          DialogEdit->SetClearFlag(1);
        }

      /* $ 01.08.2000 SVS
         ��� �� ����� ���� DIF_USELASTHISTORY � �������� ������ �����,
         �� ��������������� ������ �������� �� History
      */
      if(CurItem->Type==DI_EDIT &&
        (ItemFlags&(DIF_HISTORY|DIF_USELASTHISTORY)) == (DIF_HISTORY|DIF_USELASTHISTORY))
      {
        char RegKey[NM];
        char *PtrData;
        int PtrLength;
        if(ItemFlags&DIF_VAREDIT)
        {
          PtrData  =(char *)CurItem->Ptr.PtrData;
          PtrLength=CurItem->Ptr.PtrLength;
        }
        else
        {
          PtrData  =CurItem->Data;
          PtrLength=sizeof(CurItem->Data);
        }
        if(!PtrData[0])
        {
          DWORD UseFlags;
          sprintf(RegKey,fmtSavedDialogHistory,(char*)CurItem->History);
          UseFlags=GetRegKey(RegKey,"Flags",1);
          if(UseFlags)
            GetRegKey(RegKey,"Line0",PtrData,"",PtrLength);
        }
      }
      /* SVS $ */
      if((ItemFlags&DIF_MANUALADDHISTORY) && !(ItemFlags&DIF_HISTORY))
        ItemFlags&=~DIF_MANUALADDHISTORY; // ������� �����.

      /* $ 18.03.2000 SVS
         ���� ��� ComBoBox � ������ �� �����������, �� ����� �� ������
         ��� �������, ��� ���� ���� �� ������� ����� Selected != 0
      */
      if (Type==DI_COMBOBOX &&
          (!(ItemFlags&DIF_VAREDIT) && CurItem->Data[0] == 0 ||
            (ItemFlags&DIF_VAREDIT) && *(char*)CurItem->Ptr.PtrData == 0) &&
          CurItem->ListItems)
      {
        struct FarListItem *ListItems=CurItem->ListItems->Items;
        int Length=CurItem->ListItems->ItemsNumber;

        //CurItem->ListPtr->AddItem(CurItem->ListItems);

        for (J=0; J < Length; J++)
        {
          if(ListItems[J].Flags & LIF_SELECTED)
          {
            // ����� ������ ������ ����� ��� ������� ��������������
            if(ItemFlags&DIF_VAREDIT)
              strncpy((char *)CurItem->Ptr.PtrData, ListItems[J].Text,CurItem->Ptr.PtrLength-1);
            else
              strncpy(CurItem->Data, ListItems[J].Text,sizeof(CurItem->Data)-1);
            break;
          }
        }
      }
      /* SVS $ */
      if((CurItem->Type==DI_EDIT || CurItem->Type==DI_COMBOBOX) &&
         (ItemFlags&DIF_VAREDIT))
        DialogEdit->SetString((char *)CurItem->Ptr.PtrData);
      else
        DialogEdit->SetString(CurItem->Data);

      if (Type==DI_FIXEDIT)
        DialogEdit->SetCurPos(0);

      /* $ 30.08.2001 VVM
        + ��� ������� ����� ������� ���������� ����� */
      if (!(ItemFlags&DIF_EDITOR))
        DialogEdit->SetPersistentBlocks(Opt.DialogsEditBlock);
      /*  VVM $ */
    }
    if (Type == DI_USERCONTROL)
    {
      if (!DialogMode.Check(DMODE_CREATEOBJECTS))
        CurItem->ObjPtr=new COORD; // ���� ����������� ��������� ��������� �������
      ((COORD *)(CurItem->ObjPtr))->X=-1;
      ((COORD *)(CurItem->ObjPtr))->Y=-1;
    }

    CurItem->Flags=ItemFlags;
  }
  // ���� ����� ��������, �� ����������� ����� �������.
  SelectOnEntry(FocusPos,TRUE);

  // ��� ������� �������!
  DialogMode.Set(DMODE_CREATEOBJECTS);
  return FocusPos;
}
/* 24.08.2000 SVS $ */


/* $ 19.05.2001 DJ
   ����������� Title �������� � ��������� �������
*/

char *Dialog::GetDialogTitle()
{
  for(int I=0; I < ItemCount; I++)
  {
    DialogItem *CurItem=&Item[I];

    // �� ������� ����������� "������" ��������� ��������� �������!
    if ((CurItem->Type==DI_TEXT ||
          CurItem->Type==DI_DOUBLEBOX ||
          CurItem->Type==DI_SINGLEBOX))
    {
      for (int J=0;CurItem->Data[J]!=0;J++)
        if (LocalIsalpha(CurItem->Data[J]))
          return(CurItem->Data+J);
    }
  }
  return "";
}

/* DJ $ */


/* $ 30.05.2001 KM
   ��������� ��������� �/��� �������� ����� �������.
*/
BOOL Dialog::SetItemRect(int ID,SMALL_RECT *Rect)
{
  if (ID >= ItemCount)
    return FALSE;

  DialogItem *CurItem=&Item[ID];
  int Type=CurItem->Type;

  /* $ 10.08.2001 KM
    - �������� ����������� X1 � 0 ��� Rect->Left=-1 (������������ �����).
  */
  CurItem->X1=(unsigned char)Rect->Left;
  /* KM $ */
  CurItem->Y1=(Rect->Top<0)?0:Rect->Top;

  if (IsEdit(Type))
  {
      Edit *DialogEdit=(Edit *)CurItem->ObjPtr;
      CurItem->X2=(unsigned char)Rect->Right;
      CurItem->Y2=0;
      DialogEdit->SetPosition(X1+Rect->Left, Y1+Rect->Top,
                                   X1+Rect->Right,Y1+Rect->Top);
  }
  else if (Type==DI_LISTBOX)
  {
      CurItem->X2=(unsigned char)Rect->Right;
      CurItem->Y2=(unsigned char)Rect->Bottom;
      CurItem->ListPtr->SetPosition(X1+Rect->Left, Y1+Rect->Top,
                                    X1+Rect->Right,Y1+Rect->Bottom);
  }
  switch(Type)
  {
    case DI_DOUBLEBOX:
    case DI_SINGLEBOX:
    case DI_USERCONTROL:
      CurItem->X2=(unsigned char)Rect->Right;
      CurItem->Y2=(unsigned char)Rect->Bottom;
      break;
  }

  if(DialogMode.Check(DMODE_SHOW))
  {
    ShowDialog(-1);
    ScrBuf.Flush();
  }
  return TRUE;
}
/* KM $ */

BOOL Dialog::GetItemRect(int I,RECT& Rect)
{
  if(I >= ItemCount)
    return FALSE;

  struct DialogItem *CurItem=&Item[I];
  DWORD ItemFlags=CurItem->Flags;
  int Type=CurItem->Type;
  int Len;

  Rect.left=(int)CurItem->X1;
  Rect.top=(int)CurItem->Y1;
  Rect.right=(int)CurItem->X2;
  Rect.bottom=(int)CurItem->Y2;

  switch(Type)
  {
    case DI_COMBOBOX:
    case DI_EDIT:
    case DI_FIXEDIT:
    case DI_PSWEDIT:
    case DI_LISTBOX:
      break;
    default:
      Len=((ItemFlags & DIF_SHOWAMPERSAND)?strlen(CurItem->Data):HiStrlen(CurItem->Data));
      break;
  }

  switch(Type)
  {
    case DI_TEXT:
      if (CurItem->X1==(unsigned char)-1)
        Rect.left=(X2-X1+1-Len)/2;
      if(Rect.left < 0)
        Rect.left=0;

      if (CurItem->Y1==(unsigned char)-1)
        Rect.top=(Y2-Y1+1)/2;

      if(Rect.top < 0)
        Rect.top=0;

      Rect.bottom=Rect.top;
      Rect.right=Rect.left+Len;

      if (ItemFlags & (DIF_SEPARATOR|DIF_SEPARATOR2))
      {
        Rect.bottom=Rect.top;
        Rect.left=(!DialogMode.Check(DMODE_SMALLDIALOG)?3:0); //???
        Rect.right=X2-X1-(!DialogMode.Check(DMODE_SMALLDIALOG)?5:0); //???
      }
      break;

    case DI_VTEXT:
      if (CurItem->X1==(unsigned char)-1)
        Rect.left=(X2-X1+1)/2;
      if(Rect.left < 0)
        Rect.left=0;

      if (CurItem->Y1==(unsigned char)-1)
        Rect.top=(Y2-Y1+1-strlen(CurItem->Data))/2;

      if(Rect.top < 0)
        Rect.top=0;

      Rect.right=Rect.left;
      Rect.bottom=Rect.top+Len;
      /* ������� �� ���� �� �������.
      if (ItemFlags & (DIF_SEPARATOR|DIF_SEPARATOR2))
      {
        Rect.right=Rect.left;
        Rect.top=(!DialogMode.Check(DMODE_SMALLDIALOG)?1:0); //???
        Rect.bottom=Y2-Y1-(!DialogMode.Check(DMODE_SMALLDIALOG)?1:0); //???
        break;
      }
      */
      break;

    case DI_BUTTON:
      Rect.bottom=Rect.top;
      Rect.right=Rect.left+Len;
      break;

    case DI_CHECKBOX:
    case DI_RADIOBUTTON:
      Rect.bottom=Rect.top;
      Rect.right=Rect.left+Len+(Type == DI_CHECKBOX?4:
                                 (ItemFlags & DIF_MOVESELECT?3:4)
                               );
      break;

    case DI_COMBOBOX:
    case DI_EDIT:
    case DI_FIXEDIT:
    case DI_PSWEDIT:
      Rect.bottom=Rect.top;
      break;
  }
  return TRUE;
}


//////////////////////////////////////////////////////////////////////////
/* Private:
   ��������� ������ � �������� "����������"
*/
void Dialog::DeleteDialogObjects()
{
  int I;
  struct DialogItem *CurItem;

  for (I=0; I < ItemCount; I++)
  {
    CurItem=Item+I;
    switch(CurItem->Type)
    {
      case DI_EDIT:
      case DI_FIXEDIT:
      case DI_PSWEDIT:
      case DI_COMBOBOX:
        if(CurItem->ObjPtr)
          delete (Edit *)(CurItem->ObjPtr);
      case DI_LISTBOX:
        if((CurItem->Type == DI_COMBOBOX || CurItem->Type == DI_LISTBOX) &&
            CurItem->ListPtr)
           delete CurItem->ListPtr;
        break;
      case DI_USERCONTROL:
        if(CurItem->ObjPtr)
          delete (COORD *)(CurItem->ObjPtr);
        break;
    }
  }
}


//////////////////////////////////////////////////////////////////////////
/* Public:
   ��������� �������� �� ����� ��������������.
   ��� ������������� ����� DIF_HISTORY, ��������� ������ � �������.
*/
void Dialog::GetDialogObjectsData()
{
  int I;
  struct DialogItem *CurItem;

  for (I=0; I < ItemCount; I++)
  {
    if((CurItem=Item+I)->ObjPtr)
    {
      int Type=CurItem->Type;
      DWORD IFlags=CurItem->Flags;
      switch(Type)
      {
        case DI_EDIT:
        case DI_FIXEDIT:
        case DI_PSWEDIT:
        case DI_COMBOBOX:
        {
          char *PtrData;
          int PtrLength;
          Edit *EditPtr=(Edit *)(CurItem->ObjPtr);
          // ���������� ������
          if((Type==DI_EDIT || Type==DI_COMBOBOX) && (IFlags&DIF_VAREDIT))
          {
            PtrData  =(char *)CurItem->Ptr.PtrData;
            PtrLength=CurItem->Ptr.PtrLength;
          }
          else
          {
            PtrData  =CurItem->Data;
            PtrLength=sizeof(CurItem->Data);
          }

          // ������� ������
          EditPtr->GetString(PtrData,PtrLength);

          if (ExitCode >=0 &&
              (IFlags & DIF_HISTORY) &&
              !(IFlags & DIF_MANUALADDHISTORY) && // ��� ������� �� ���������
              CurItem->History &&
              Opt.DialogsEditHistory)
            AddToEditHistory(PtrData,CurItem->History);
          //if(Type == DI_COMBOBOX)
          //{
          //  ListItems
          //}
          /* $ 01.08.2000 SVS
             ! � History ������ ��������� �������� (��� DIF_EXPAND...) �����
              ����������� �����!
          */
          /*$ 05.07.2000 SVS $
          �������� - ���� ������� ������������ ���������� ���������� �����?
          �.�. ������� GetDialogObjectsData() ����� ���������� ��������������
          �� ���� ���������!*/
          /* $ 04.12.2000 SVS
            ! ��� DI_PSWEDIT � DI_FIXEDIT ��������� DIF_EDITEXPAND �� �����
             (DI_FIXEDIT ����������� ��� ������ ���� ���� �����)
          */
          if((IFlags&DIF_EDITEXPAND) && Type != DI_PSWEDIT && Type != DI_FIXEDIT)
             ExpandEnvironmentStr(PtrData, PtrData,PtrLength-1);
          /* SVS $ */
          /* SVS $ */
          /* 01.08.2000 SVS $ */
          break;
        }

        case DI_LISTBOX:
        {
          CurItem->ListPos=CurItem->ListPtr->GetSelectPos();
          break;
        }

        /**/
      }
    }
  }
}


//////////////////////////////////////////////////////////////////////////
/* $ 22.08.2000 SVS
  ! ShowDialog - �������������� �������� - ����� ������� ������������
*/
/* Private:
   ��������� ��������� ������� �� ������.
*/
void Dialog::ShowDialog(int ID)
{
  struct DialogItem *CurItem;
  int X,Y;
  int I,DrawItemCount;
  unsigned long Attr;

  /* $ 18.08.2000 SVS
     ���� �� ��������� ���������, �� ����������.
  */
  if(IsEnableRedraw ||                 // ��������� ���������� ?
     (ID+1 > ItemCount) ||             // � ����� � ������ ������������?
     DialogMode.Check(DMODE_DRAWING) || // ������ ��������?
     !DialogMode.Check(DMODE_SHOW) ||   // ���� �� �����, �� � �� ������������.
     !DialogMode.Check(DMODE_INITOBJECTS))
    return;
  /* SVS $ */

  DialogMode.Set(DMODE_DRAWING);  // ������ ��������!!!

  ChangePriority ChPriority(THREAD_PRIORITY_NORMAL);

  if(ID == -1) // ������ ���?
  {
    /* $ 28.07.2000 SVS
       ����� ����������� ������� �������� ��������� � ����������
    */
    if(!DlgProc((HANDLE)this,DN_DRAWDIALOG,0,0))
    {
      DialogMode.Skip(DMODE_DRAWING);  // ����� ��������� �������!!!
      return;
    }
    /* SVS $ */

    /* $ 28.07.2000 SVS
       ����� ����������� �������� ���� �������...
    */
    if(!DialogMode.Check(DMODE_SMALLDIALOG))
    {
      Attr=DlgProc((HANDLE)this,DN_CTLCOLORDIALOG,0,
          DialogMode.Check(DMODE_WARNINGSTYLE) ? COL_WARNDIALOGTEXT:COL_DIALOGTEXT);
      SetScreen(X1,Y1,X2,Y2,' ',Attr);
    }
    /* SVS $ */
  }

  if(ID == -1) // ������ ���?
  {
    ID=0;
    DrawItemCount=ItemCount;
  }
  else
  {
    DrawItemCount=ID+1;
  }

  for (I=ID; I < DrawItemCount; I++)
  {
    CurItem=&Item[I];

    if(CurItem->Flags&DIF_HIDDEN)
      continue;

    /* $ 28.07.2000 SVS
       ����� ����������� ������� �������� �������� ���������
       ����������� ������� SendDlgMessage - � ��� �������� ���!
    */
    if(!Dialog::SendDlgMessage((HANDLE)this,DN_DRAWDLGITEM,I,0))
       continue;
    /* SVS $ */
    /* $ 28.07.2000 SVS
       ����� ����������� ������� �������� ������� ������� �������� ���������
    */
    switch(CurItem->Type)
    {
/* ***************************************************************** */
      case DI_USERCONTROL:
        if(CurItem->VBuf)
        {
          COORD *Coord=(COORD *)(CurItem->ObjPtr);
          PutText(X1+CurItem->X1,Y1+CurItem->Y1,X1+CurItem->X2,Y1+CurItem->Y2,CurItem->VBuf);
          // �� ������� ����������� ������, ���� �� ���������������.
          if(FocusPos == I)
          {
            if(Coord->X != -1 && Coord->Y != -1)
            {
              MoveCursor(Coord->X+CurItem->X1+X1,Coord->Y+CurItem->Y1+Y1);
              SetCursorType(1,-1);
            }
            else
              SetCursorType(0,-1);
          }
        }
        break; //��� ����������� :-)))

/* ***************************************************************** */
      case DI_SINGLEBOX:
      case DI_DOUBLEBOX:
      {
        Attr=MAKELONG(
          MAKEWORD(FarColorToReal(DialogMode.Check(DMODE_WARNINGSTYLE) ?
                      ((CurItem->Flags&DIF_DISABLE)?COL_WARNDIALOGDISABLED:COL_WARNDIALOGBOXTITLE):
                      ((CurItem->Flags&DIF_DISABLE)?COL_DIALOGDISABLED:COL_DIALOGBOXTITLE)), // Title LOBYTE
                 FarColorToReal(DialogMode.Check(DMODE_WARNINGSTYLE) ?
                      ((CurItem->Flags&DIF_DISABLE)?COL_WARNDIALOGDISABLED:COL_WARNDIALOGHIGHLIGHTTEXT):
                      ((CurItem->Flags&DIF_DISABLE)?COL_DIALOGDISABLED:COL_DIALOGHIGHLIGHTTEXT))),// HiText HIBYTE
          MAKEWORD(FarColorToReal(DialogMode.Check(DMODE_WARNINGSTYLE) ?
                  ((CurItem->Flags&DIF_DISABLE)?COL_WARNDIALOGDISABLED:COL_WARNDIALOGBOX):
                  ((CurItem->Flags&DIF_DISABLE)?COL_DIALOGDISABLED:COL_DIALOGBOX)), // Box LOBYTE
                 0)                                               // HIBYTE
        );
        Attr=DlgProc((HANDLE)this,DN_CTLCOLORDLGITEM,I,Attr);

        Box(X1+CurItem->X1,Y1+CurItem->Y1,X1+CurItem->X2,Y1+CurItem->Y2,
            LOBYTE(HIWORD(Attr)),
            (CurItem->Type==DI_SINGLEBOX) ? SINGLE_BOX:DOUBLE_BOX);

        if (*CurItem->Data)
        {
          char Title[200];
          int XB;

          sprintf(Title," %s ",CurItem->Data);
          XB=X1+CurItem->X1+(CurItem->X2-CurItem->X1+1-HiStrlen(Title))/2;

          if (CurItem->Flags & DIF_LEFTTEXT && X1+CurItem->X1+1 < XB)
            XB=X1+CurItem->X1+1;

          SetColor(Attr&0xFF);
          GotoXY(XB,Y1+CurItem->Y1);
          //HiText(Title,HIBYTE(LOWORD(Attr)));
          if (CurItem->Flags & DIF_SHOWAMPERSAND)
            Text(Title);
          else
            HiText(Title,HIBYTE(LOWORD(Attr)));
        }
        break;
      }

/* ***************************************************************** */
      case DI_TEXT:
      {
        if (CurItem->X1==(unsigned char)-1)
          X=(X2-X1+1-((CurItem->Flags & DIF_SHOWAMPERSAND)?HiStrlen(CurItem->Data):strlen(CurItem->Data)))/2;
        else
          X=CurItem->X1;

        if (CurItem->Y1==(unsigned char)-1)
          Y=(Y2-Y1+1)/2;
        else
          Y=CurItem->Y1;

        if (CurItem->Flags & DIF_SETCOLOR)
          Attr=CurItem->Flags & DIF_COLORMASK;
        else
          if (CurItem->Flags & DIF_BOXCOLOR)
            Attr=DialogMode.Check(DMODE_WARNINGSTYLE) ?
                  ((CurItem->Flags&DIF_DISABLE)?COL_WARNDIALOGDISABLED:COL_WARNDIALOGBOX):
                  ((CurItem->Flags&DIF_DISABLE)?COL_DIALOGDISABLED:COL_DIALOGBOX);
          else
            Attr=DialogMode.Check(DMODE_WARNINGSTYLE) ?
                  ((CurItem->Flags&DIF_DISABLE)?COL_WARNDIALOGDISABLED:COL_WARNDIALOGTEXT):
                  ((CurItem->Flags&DIF_DISABLE)?COL_DIALOGDISABLED:COL_DIALOGTEXT);

        Attr=MAKELONG(
           MAKEWORD(FarColorToReal(Attr),
                   FarColorToReal(DialogMode.Check(DMODE_WARNINGSTYLE) ?
                      ((CurItem->Flags&DIF_DISABLE)?COL_WARNDIALOGDISABLED:COL_WARNDIALOGHIGHLIGHTTEXT):
                      ((CurItem->Flags&DIF_DISABLE)?COL_DIALOGDISABLED:COL_DIALOGHIGHLIGHTTEXT))), // HIBYTE HiText
             0);
        Attr=DlgProc((HANDLE)this,DN_CTLCOLORDLGITEM,I,Attr);
        SetColor(Attr&0xFF);

        if (CurItem->Flags & (DIF_SEPARATOR|DIF_SEPARATOR2))
        {
          GotoXY(X1+(!DialogMode.Check(DMODE_SMALLDIALOG)?3:0),Y1+Y); //????
          if (DialogTooLong)
            ShowSeparator(DialogTooLong-(!DialogMode.Check(DMODE_SMALLDIALOG)?5:0),(CurItem->Flags&DIF_SEPARATOR2?3:1));
          else
            ShowSeparator(X2-X1-(!DialogMode.Check(DMODE_SMALLDIALOG)?5:0),(CurItem->Flags&DIF_SEPARATOR2?3:1));
        }

        GotoXY(X1+X,Y1+Y);

        if (CurItem->Flags & DIF_SHOWAMPERSAND)
          Text(CurItem->Data);
        else
          HiText(CurItem->Data,HIBYTE(LOWORD(Attr)));

        break;
      }

/* ***************************************************************** */
      case DI_VTEXT:
      {
        if (CurItem->X1==(unsigned char)-1)
          X=(X2-X1+1)/2;
        else
          X=CurItem->X1;

        if (CurItem->Y1==(unsigned char)-1)
          Y=(Y2-Y1+1-strlen(CurItem->Data))/2;
        else
          Y=CurItem->Y1;

        if (CurItem->Flags & DIF_BOXCOLOR)
          Attr=DialogMode.Check(DMODE_WARNINGSTYLE) ?
                   ((CurItem->Flags&DIF_DISABLE)?COL_WARNDIALOGDISABLED:COL_WARNDIALOGBOX):
                   ((CurItem->Flags&DIF_DISABLE)?COL_DIALOGDISABLED:COL_DIALOGBOX);
        else
          if (CurItem->Flags & DIF_SETCOLOR)
            Attr=(CurItem->Flags & DIF_COLORMASK);
          else
            Attr=(DialogMode.Check(DMODE_WARNINGSTYLE) ?
                   ((CurItem->Flags&DIF_DISABLE)?COL_WARNDIALOGDISABLED:COL_WARNDIALOGTEXT):
                   ((CurItem->Flags&DIF_DISABLE)?COL_DIALOGDISABLED:COL_DIALOGTEXT));

        Attr=DlgProc((HANDLE)this,DN_CTLCOLORDLGITEM,I,FarColorToReal(Attr));
        SetColor(Attr&0xFF);

        /* ������� �� ���� �� �������.
        if (CurItem->Flags & (DIF_SEPARATOR|DIF_SEPARATOR2))
        {
          GotoXY(X1+X,Y1+(!DialogMode.Check(DMODE_SMALLDIALOG)?1:0)); //????
          if (DialogTooLong)
            ShowSeparator(DialogTooLong-(!DialogMode.Check(DMODE_SMALLDIALOG)?1:0),5);
          else
            ShowSeparator(Y2-Y1-(!DialogMode.Check(DMODE_SMALLDIALOG)?1:0),5);
        }
        */

        GotoXY(X1+X,Y1+Y);
        VText(CurItem->Data);
        break;
      }

/* ***************************************************************** */
      /* $ 18.07.2000 SVS
         + ��������� �������� DI_COMBOBOX
      */
      case DI_EDIT:
      case DI_FIXEDIT:
      case DI_PSWEDIT:
      case DI_COMBOBOX:
      {
        Edit *EditPtr=(Edit *)(CurItem->ObjPtr);
        if(!EditPtr)
          break;

        /* $ 15.08.2000 SVS
           ! ��� DropDownList ����� ������������ �� �����
        */
        if(CurItem->Type == DI_COMBOBOX && (CurItem->Flags & DIF_DROPDOWNLIST))
        {
          if(DialogMode.Check(DMODE_WARNINGSTYLE))
            Attr=MAKELONG(
              MAKEWORD( //LOWORD
                // LOLO (Text)
                FarColorToReal((CurItem->Flags&DIF_DISABLE)?COL_WARNDIALOGEDITDISABLED:COL_WARNDIALOGEDIT),
                // LOHI (Select)
                FarColorToReal((CurItem->Flags&DIF_DISABLE)?COL_DIALOGEDITDISABLED:COL_DIALOGEDITSELECTED)
              ),
              MAKEWORD( //HIWORD
                // HILO (Unchanged)
                FarColorToReal(COL_DIALOGEDITUNCHANGED),
                // HIHI (History)
                FarColorToReal((CurItem->Flags&DIF_DISABLE)?COL_WARNDIALOGDISABLED:COL_WARNDIALOGTEXT)
              )
            );
          else
            Attr=MAKELONG(
              MAKEWORD( //LOWORD
                // LOLO (Text)
                FarColorToReal((CurItem->Flags&DIF_DISABLE)?COL_DIALOGEDITDISABLED:(!CurItem->Focus?COL_DIALOGEDIT:COL_DIALOGEDITSELECTED)),
                // LOHI (Select)
                FarColorToReal((CurItem->Flags&DIF_DISABLE)?COL_DIALOGEDITDISABLED:(!CurItem->Focus?COL_DIALOGEDIT:COL_DIALOGEDITSELECTED))
              ),
              MAKEWORD( //HIWORD
                // HILO (Unchanged)
                FarColorToReal(COL_DIALOGEDITUNCHANGED),
                // HIHI (History)
                FarColorToReal((CurItem->Flags&DIF_DISABLE)?COL_DIALOGDISABLED:COL_DIALOGTEXT)
              )
            );
        }
        else
        {
          if(DialogMode.Check(DMODE_WARNINGSTYLE))
            Attr=MAKELONG(
              MAKEWORD( //LOWORD
                // LOLO (Text)
                FarColorToReal((CurItem->Flags&DIF_DISABLE)?COL_WARNDIALOGEDITDISABLED:
                  (CurItem->Flags&DIF_NOFOCUS?COL_DIALOGEDITUNCHANGED:COL_WARNDIALOGEDIT)),
                // LOHI (Select)
                FarColorToReal((CurItem->Flags&DIF_DISABLE)?COL_DIALOGEDITDISABLED:COL_DIALOGEDITSELECTED)
              ),
              MAKEWORD( //HIWORD
                // HILO (Unchanged)
                FarColorToReal(COL_DIALOGEDITUNCHANGED),
                // HIHI (History)
                FarColorToReal((CurItem->Flags&DIF_DISABLE)?COL_WARNDIALOGDISABLED:COL_WARNDIALOGTEXT)
              )
            );
          else
            Attr=MAKELONG(
              MAKEWORD( //LOWORD
                // LOLO (Text)
                FarColorToReal((CurItem->Flags&DIF_DISABLE)?COL_DIALOGEDITDISABLED:
                  (CurItem->Flags&DIF_NOFOCUS?COL_DIALOGEDITUNCHANGED:COL_DIALOGEDIT)),
                // LOHI (Select)
                FarColorToReal((CurItem->Flags&DIF_DISABLE)?COL_DIALOGEDITDISABLED:COL_DIALOGEDITSELECTED)
              ),
              MAKEWORD( //HIWORD
                // HILO (Unchanged)
                FarColorToReal(COL_DIALOGEDITUNCHANGED),
                // HIHI (History)
                FarColorToReal((CurItem->Flags&DIF_DISABLE)?COL_DIALOGDISABLED:COL_DIALOGTEXT)
              )
            );
        }
        /* SVS $ */
        /* SVS $ */
        Attr=DlgProc((HANDLE)this,DN_CTLCOLORDLGITEM,I,Attr);

        EditPtr->SetObjectColor(Attr&0xFF,HIBYTE(LOWORD(Attr)),LOBYTE(HIWORD(Attr)));

        if (CurItem->Focus)
        {
          /* $ 09.08.2000 KM
             ���������� ��������� ������� ��� ����������� �������
          */
          if (!DialogMode.Check(DMODE_DRAGGED))
            SetCursorType(1,-1);
          EditPtr->Show();
          /* KM $ */
        }
        else
        {
          EditPtr->FastShow();
          EditPtr->SetLeftPos(0);
        }

        /* $ 09.08.2000 KM
           ���������� ��������� ������� ��� ����������� �������
        */
        if (DialogMode.Check(DMODE_DRAGGED))
          SetCursorType(FALSE,0);
        /* KM $ */

        if (CurItem->History &&
             ((CurItem->Flags & DIF_HISTORY) &&
              Opt.DialogsEditHistory
              || CurItem->Type == DI_COMBOBOX))
        {
          int EditX1,EditY1,EditX2,EditY2;

          EditPtr->GetPosition(EditX1,EditY1,EditX2,EditY2);
          //Text((CurItem->Type == DI_COMBOBOX?"\x1F":"\x19"));
          Text(EditX2+1,EditY1,HIBYTE(HIWORD(Attr)),"\x19");
        }
        break;
        /* SVS $ */
      }

/* ***************************************************************** */
      /* $ 01.08.2000 SVS
         ������� ListBox
      */
      case DI_LISTBOX:
      {
        if(CurItem->ListPtr)
        {
          /* $ 21.08.2000 SVS
             ����� ���������� ������� �� ��������� �������� ���������
          */
          short Colors[VMENU_COLOR_COUNT];
          CurItem->ListPtr->GetColors(Colors);
          if(DlgProc((HANDLE)this,DN_CTLCOLORDLGLIST,
                          sizeof(Colors)/sizeof(Colors[0]),(long)Colors))
            CurItem->ListPtr->SetColors(Colors);
          /* SVS $ */
          if (CurItem->Focus)
            CurItem->ListPtr->Show();
          else
            CurItem->ListPtr->FastShow();
        }
        break;
      }
      /* 01.08.2000 SVS $ */

/* ***************************************************************** */
      case DI_CHECKBOX:
      case DI_RADIOBUTTON:
      {
        if (CurItem->Flags & DIF_SETCOLOR)
          Attr=(CurItem->Flags & DIF_COLORMASK);
        else
          Attr=(DialogMode.Check(DMODE_WARNINGSTYLE) ?
                  ((CurItem->Flags&DIF_DISABLE)?COL_WARNDIALOGDISABLED:COL_WARNDIALOGTEXT):
                  ((CurItem->Flags&DIF_DISABLE)?COL_DIALOGDISABLED:COL_DIALOGTEXT));

        Attr=MAKEWORD(FarColorToReal(Attr),
             FarColorToReal(DialogMode.Check(DMODE_WARNINGSTYLE) ?
                   ((CurItem->Flags&DIF_DISABLE)?COL_WARNDIALOGDISABLED:COL_WARNDIALOGHIGHLIGHTTEXT):
                   ((CurItem->Flags&DIF_DISABLE)?COL_DIALOGDISABLED:COL_DIALOGHIGHLIGHTTEXT))); // HiText
        Attr=DlgProc((HANDLE)this,DN_CTLCOLORDLGITEM,I,Attr);

        SetColor(Attr&0xFF);

        GotoXY(X1+CurItem->X1,Y1+CurItem->Y1);

        if (CurItem->Type==DI_CHECKBOX)
        {
          char *Chk3State=MSG(MCheckBox2State);
          mprintf("[%c] ",CurItem->Selected ?
             (((CurItem->Flags&DIF_3STATE) && CurItem->Selected == 2)?
                *Chk3State:'x'):' ');
        }
        else
          if (CurItem->Flags & DIF_MOVESELECT)
            mprintf(" %c ",CurItem->Selected ? '\07':' ');
          else
            mprintf("(%c) ",CurItem->Selected ? '\07':' ');

        if (CurItem->Flags & DIF_SHOWAMPERSAND)
          Text(CurItem->Data);
        else
          HiText(CurItem->Data,HIBYTE(LOWORD(Attr)));

        if (CurItem->Focus)
        {
          /* $ 09.08.2000 KM
             ���������� ��������� ������� ��� ����������� �������
          */
          if (!DialogMode.Check(DMODE_DRAGGED))
            SetCursorType(1,-1);
          MoveCursor(X1+CurItem->X1+1,Y1+CurItem->Y1);
          /* KM $ */
        }

        break;
      }

/* ***************************************************************** */
      case DI_BUTTON:
      {
        GotoXY(X1+CurItem->X1,Y1+CurItem->Y1);

        /* $ 18.08.2000 SVS
           + DI_BUTTON ���� ������ ����� ����� DIF_SETCOLOR
        */
        if (CurItem->Focus)
        {
          SetCursorType(0,10);
          Attr=MAKEWORD(
             (CurItem->Flags & DIF_SETCOLOR)?(CurItem->Flags & DIF_COLORMASK):
               FarColorToReal(DialogMode.Check(DMODE_WARNINGSTYLE) ?
                   ((CurItem->Flags&DIF_DISABLE)?COL_WARNDIALOGDISABLED:COL_WARNDIALOGSELECTEDBUTTON):
                   ((CurItem->Flags&DIF_DISABLE)?COL_DIALOGDISABLED:COL_DIALOGSELECTEDBUTTON)), // TEXT
             FarColorToReal(DialogMode.Check(DMODE_WARNINGSTYLE) ?
                   ((CurItem->Flags&DIF_DISABLE)?COL_WARNDIALOGDISABLED:COL_WARNDIALOGHIGHLIGHTSELECTEDBUTTON):
                   ((CurItem->Flags&DIF_DISABLE)?COL_DIALOGDISABLED:COL_DIALOGHIGHLIGHTSELECTEDBUTTON))); // HiText
        }
        else
        {
          Attr=MAKEWORD(
             (CurItem->Flags & DIF_SETCOLOR)?(CurItem->Flags & DIF_COLORMASK):
               FarColorToReal(DialogMode.Check(DMODE_WARNINGSTYLE) ?
                      ((CurItem->Flags&DIF_DISABLE)?COL_WARNDIALOGDISABLED:COL_WARNDIALOGBUTTON):
                      ((CurItem->Flags&DIF_DISABLE)?COL_DIALOGDISABLED:COL_DIALOGBUTTON)), // TEXT
             FarColorToReal(DialogMode.Check(DMODE_WARNINGSTYLE) ?
                      ((CurItem->Flags&DIF_DISABLE)?COL_WARNDIALOGDISABLED:COL_WARNDIALOGHIGHLIGHTBUTTON):
                      ((CurItem->Flags&DIF_DISABLE)?COL_DIALOGDISABLED:COL_DIALOGHIGHLIGHTBUTTON))); // HiText
        }
        /* SVS $ */
        Attr=DlgProc((HANDLE)this,DN_CTLCOLORDLGITEM,I,Attr);
        SetColor(Attr&0xFF);
        if (CurItem->Flags & DIF_SHOWAMPERSAND)
          Text(CurItem->Data);
        else
          HiText(CurItem->Data,HIBYTE(LOWORD(Attr)));
        break;
      }

/* ***************************************************************** */
    } // end switch(...
    /* 28.07.2000 SVS $ */
  } // end for (I=...

  // �������!
  // �� �������� ;-)
  for (I=0; I < ItemCount; I++)
  {
    CurItem=&Item[I];
    if(CurItem->ListPtr && GetDropDownOpened() && CurItem->ListPtr->IsVisible())
    {
      if((CurItem->Type == DI_COMBOBOX) ||
         ((CurItem->Type == DI_EDIT || CurItem->Type == DI_FIXEDIT) &&
         !(CurItem->Flags&DIF_HIDDEN) &&
         (CurItem->Flags&DIF_HISTORY)))
      {
        CurItem->ListPtr->Show();
      }
    }
  }
  /* $ 31.07.2000 SVS
     ������� ��������� �����������...
  */
  if ( DialogMode.Check(DMODE_DRAGGED) ) // ���� ������ ���������
  {
    DlgProc((HANDLE)this,DN_DRAWDIALOG,1,0);
  }
  else
  {
    /* $ 03.06.2001 KM
       + ��� ������ ����������� �������, ����� ������ �����������, �������������
         ��������� �������, � ��������� ������ �� �� ������ ����������������.
    */
    SetFarTitle(GetDialogTitle());
    /* KM $ */
  }
  /* SVS $ */

  DialogMode.Skip(DMODE_DRAWING);  // ����� ��������� �������!!!
  DialogMode.Set(DMODE_SHOW); // ������ �� ������!
}
/* SVS 22.08.2000 $ */


//////////////////////////////////////////////////////////////////////////
/* Public, Virtual:
   ��������� ������ �� ����������.
   ����������� BaseInput::ProcessKey.
*/
int Dialog::ProcessKey(int Key)
{
  int I,J;
  char Str[1024];
  Edit *CurEditLine;

  if (Key==KEY_NONE || Key==KEY_IDLE)
  {
    /* $ 28.07.2000 SVS
       ��������� ���� ���� � ���������� :-)
    */
    DlgProc((HANDLE)this,DN_ENTERIDLE,0,0);
    /* SVS $ */
    return(FALSE);
  }

  /* $ 31.07.2000 tran
     + ����������� ������� �� ������ */
  if (DialogMode.Check(DMODE_DRAGGED)) // ���� ������ ���������
  {
    int rr=1;
    /* $ 15.12.2000 SVS
       ��� ����������� ������� ��������� ��������� "�����������" ����.
    */
    switch (Key)
    {
        case KEY_CTRLLEFT:
        case KEY_CTRLHOME:
        case KEY_HOME:
            rr=Key == KEY_CTRLLEFT?10:X1;
        case KEY_LEFT:
            Hide();
            for ( I=0; I<rr; I++ )
                if ( X1>0 )
                {
                    X1--;
                    X2--;
                    AdjustEditPos(-1,0);
                }
            if(!DialogMode.Check(DMODE_ALTDRAGGED)) Show();
            break;
        case KEY_CTRLRIGHT:
        case KEY_CTRLEND:
        case KEY_END:
            rr=Key == KEY_CTRLRIGHT?10:abs(X1-(ScrX - (X2-X1+1)))+1;
        case KEY_RIGHT:
            Hide();
            for ( I=0; I<rr; I++ )
                if ( X2<ScrX )
                {
                    X1++;
                    X2++;
                    AdjustEditPos(1,0);
                }
            if(!DialogMode.Check(DMODE_ALTDRAGGED)) Show();
            break;
        case KEY_PGUP:
        case KEY_CTRLPGUP:
        case KEY_CTRLUP:
            rr=Key == KEY_CTRLUP?5:Y1;
        case KEY_UP:
            Hide();
            for ( I=0; I<rr; I++ )
                if ( Y1>0 )
                {
                    Y1--;
                    Y2--;
                    AdjustEditPos(0,-1);
                }
            if(!DialogMode.Check(DMODE_ALTDRAGGED)) Show();
            break;
        case KEY_CTRLDOWN:
        case KEY_CTRLPGDN:
        case KEY_PGDN:
            rr=Key == KEY_CTRLDOWN? 5: abs(Y1-(ScrY - (Y2-Y1+1)))+1;
        case KEY_DOWN:
            Hide();
            for ( I=0; I<rr; I++ )
                if ( Y2<ScrY )
                {
                    Y1++;
                    Y2++;
                    AdjustEditPos(0,1);
                }
            if(!DialogMode.Check(DMODE_ALTDRAGGED)) Show();
            break;
        case KEY_ENTER:
        case KEY_CTRLF5:
            DialogMode.Skip(DMODE_DRAGGED); // �������� ��������!
            if(!DialogMode.Check(DMODE_ALTDRAGGED))
            {
              DlgProc((HANDLE)this,DN_DRAGGED,1,0);
              Show();
            }
            break;
        case KEY_ESC:
            Hide();
            AdjustEditPos(OldX1-X1,OldY1-Y1);
            X1=OldX1;
            X2=OldX2;
            Y1=OldY1;
            Y2=OldY2;
            DialogMode.Skip(DMODE_DRAGGED);
            if(!DialogMode.Check(DMODE_ALTDRAGGED))
            {
              DlgProc((HANDLE)this,DN_DRAGGED,1,TRUE);
              Show();
            }
            break;
    }
    /* SVS $ */
    if(DialogMode.Check(DMODE_ALTDRAGGED))
    {
      DialogMode.Skip(DMODE_DRAGGED|DMODE_ALTDRAGGED);
      DlgProc((HANDLE)this,DN_DRAGGED,1,0);
      Show();
    }
    return (TRUE);
  }
  /* $ 10.08.2000 SVS
     �������, ���� ���������! (IsCanMove)
  */
  if (Key == KEY_CTRLF5 && DialogMode.Check(DMODE_ISCANMOVE))
  /* SVS 10.08.2000 $*/
  {
    if(DlgProc((HANDLE)this,DN_DRAGGED,0,0)) // ���� ��������� ����������!
    {
      // �������� ���� � ���������� ����������
      DialogMode.Set(DMODE_DRAGGED);
      OldX1=X1; OldX2=X2; OldY1=Y1; OldY2=Y2;
      //# GetText(0,0,3,0,LV);
      Show();
    }
    return (TRUE);
  }
  /* tran 31.07.2000 $ */

  // "���� ������� �� ��, ��� ��� ��������..."
/* $ KEY_CTRLALTSHIFTPRESS ������� � manager OT */

  int Type=Item[FocusPos].Type;

  if(!DialogMode.Check(DMODE_KEY))
    if(DlgProc((HANDLE)this,DM_KEY,FocusPos,Key))
      return TRUE;

  // ��������� �����������
  if(Type==DI_CHECKBOX)
  {
    if(!(Item[FocusPos].Flags&DIF_3STATE))
    {
      if((Key == KEY_ADD      && !Item[FocusPos].Selected) ||
         (Key == KEY_SUBTRACT &&  Item[FocusPos].Selected))
       Key=KEY_SPACE;
    }
    /*
      ���� else �� �����, �.�. ���� ������� ����� ����������...
    */
  }
  else if(Key == KEY_ADD)
    Key='+';
  else if(Key == KEY_SUBTRACT)
    Key='-';
  else if(Key == KEY_MULTIPLY)
    Key='*';

  if(Type == DI_LISTBOX)
  {
    switch(Key)
    {
      case KEY_HOME:
      case KEY_LEFT:
      case KEY_END:
      case KEY_RIGHT:
      case KEY_UP:
      case KEY_DOWN:
      case KEY_PGUP:
      case KEY_PGDN:
        VMenu *List=Item[FocusPos].ListPtr;
        int CurListPos=List->GetSelectPos();
        int CheckedListItem=List->GetSelection(-1);
        List->ProcessKey(Key);
        int NewListPos=List->GetSelectPos();
        if(NewListPos != CurListPos)
          if(!DlgProc((HANDLE)this,DN_LISTCHANGE,FocusPos,NewListPos))
          {
            List->SetSelection(CheckedListItem,CurListPos);
            if(DialogMode.Check(DMODE_SHOW) && !(Item[FocusPos].Flags&DIF_HIDDEN))
              ShowDialog(FocusPos);
          }
        return(TRUE);
    }
  }

  /* $ 23.05.2001 VVM
    ! �� ���������� �������� � �������� �����. */
//  if(Key == KEY_DOWN && Type == DI_COMBOBOX && (Item[FocusPos].Flags&DIF_DROPDOWNLIST))
//    Key=KEY_CTRLDOWN;
  /* VVM $ */

  switch(Key)
  {
    case KEY_F1:
      // ����� ������� ������� �������� ��������� � ����������
      //   � ���� ������� ��� ����, �� ������� ���������
      if(Help::MkTopic(PluginNumber,
                 (char*)DlgProc((HANDLE)this,DN_HELP,FocusPos,
                                (HelpTopic?(long)HelpTopic:NULL)),
                 Str))
      {
        Help Hlp (Str);
      }
      return(TRUE);

    case KEY_TAB:
    case KEY_SHIFTTAB:
// ����� � ������� ������� �������!!!
      if (Item[FocusPos].Flags & DIF_EDITOR)
      {
        I=FocusPos;
        while (Item[I].Flags & DIF_EDITOR)
          I=ChangeFocus(I,(Key==KEY_TAB) ? 1:-1,TRUE);
      }
      else
      {
        I=ChangeFocus(FocusPos,(Key==KEY_TAB) ? 1:-1,TRUE);
        if (Key==KEY_SHIFTTAB)
          while (I>0 && (Item[I].Flags & DIF_EDITOR)!=0 &&
                 (Item[I-1].Flags & DIF_EDITOR)!=0 &&
                 ((Edit *)Item[I].ObjPtr)->GetLength()==0)
            I--;
      }
      ChangeFocus2(FocusPos,I);
      ShowDialog();
      return(TRUE);

    case KEY_CTRLENTER:
      for (I=0;I<ItemCount;I++)
        if (Item[I].DefaultButton)
        {
          if(Item[I].Flags&DIF_DISABLE)
          {
             // ProcessKey(KEY_DOWN); // �� ���� ���� :-)
             return TRUE;
          }
          if (!IsEdit(Item[I].Type))
            Item[I].Selected=1;
          ExitCode=I;
          /* $ 18.05.2001 DJ */
          CloseDialog();
          /* DJ $ */
          return(TRUE);
        }
      if(!DialogMode.Check(DMODE_OLDSTYLE))
      {
        DialogMode.Skip(DMODE_ENDLOOP); // ������ ���� ����
        return TRUE; // ������ ������ �� ����
      }

    case KEY_ENTER:
      if ((Item[FocusPos].Flags & DIF_EDITOR) && !(Item[FocusPos].Flags & DIF_READONLY))
      {
        int EditorLastPos;
        for (EditorLastPos=I=FocusPos;I<ItemCount;I++)
          if (IsEdit(Item[I].Type) && (Item[I].Flags & DIF_EDITOR))
            EditorLastPos=I;
          else
            break;
        if (((Edit *)(Item[EditorLastPos].ObjPtr))->GetLength()!=0)
          return(TRUE);
        for (I=EditorLastPos;I>FocusPos;I--)
        {
          int CurPos;
          if (I==FocusPos+1)
            CurPos=((Edit *)(Item[I-1].ObjPtr))->GetCurPos();
          else
            CurPos=0;
          ((Edit *)(Item[I-1].ObjPtr))->GetString(Str,sizeof(Str));
          int Length=strlen(Str);
          ((Edit *)(Item[I].ObjPtr))->SetString(CurPos>=Length ? "":Str+CurPos);
          if (CurPos<Length)
            Str[CurPos]=0;
          ((Edit *)(Item[I].ObjPtr))->SetCurPos(0);
          ((Edit *)(Item[I-1].ObjPtr))->SetString(Str);
          /* $ 28.07.2000 SVS
            ��� ��������� ��������� ������� �������� �������� ���������
            ����������� ������� SendDlgMessage - � ��� �������� ���!
          */
          Dialog::SendDlgMessage((HANDLE)this,DN_EDITCHANGE,I-1,0);
          Dialog::SendDlgMessage((HANDLE)this,DN_EDITCHANGE,I,0);
          /* SVS $ */
        }
        if (EditorLastPos>FocusPos)
        {
          ((Edit *)(Item[FocusPos].ObjPtr))->SetCurPos(0);
          ProcessKey(KEY_DOWN);
        }
        else
        {
          ShowDialog();
        }
        return(TRUE);
      }
      else if (Type==DI_BUTTON)
      {
        /* $ 21.08.2000 SVS
           ��� ������������, ���� ����� �� ������
        */
        Item[FocusPos].Selected=1;
        // ��������� - "������ ��������"
        if(Dialog::SendDlgMessage((HANDLE)this,DN_BTNCLICK,FocusPos,0))
          return TRUE;
        /* $ 06.12.2000 SVS
           ���� �� ������ ����� � ������ "�� ��� ��������" (DIF_BTNNOCLOSE), ��
           ������������, ����� - ���������� ������� ������.
        */
        if(!DialogMode.Check(DMODE_OLDSTYLE) && (Item[FocusPos].Flags&DIF_BTNNOCLOSE))
          return(TRUE);

        ExitCode=FocusPos;
        /* $ 18.05.2001 DJ */
        CloseDialog();
        /* DJ $ */
        /* SVS $ */
        /* SVS $ */
      }
#if 0
      else if(IsEdit(Type) || DialogMode.Check(DMODE_OLDSTYLE))
      {
        for (I=0;I<ItemCount;I++)
          if (Item[I].DefaultButton)
          {
            if (!IsEdit(Item[I].Type))
              Item[I].Selected=1;
            ExitCode=I;
          }

        DialogMode.Set(DMODE_ENDLOOP);
        if (ExitCode==-1)
          ExitCode=FocusPos;
      }
#else
      else
      {
        ExitCode=-1;
        for (I=0;I<ItemCount;I++)
          if (Item[I].DefaultButton && !(Item[I].Flags&DIF_BTNNOCLOSE))
          {
            if(Item[I].Flags&DIF_DISABLE)
            {
               // ProcessKey(KEY_DOWN); // �� ���� ���� :-)
               return TRUE;
            }
            if (!IsEdit(Item[I].Type))
              Item[I].Selected=1;
            ExitCode=I;
          }
      }

      if (ExitCode==-1)
        ExitCode=FocusPos;
      /* $ 18.05.2001 DJ */
      CloseDialog();
      /* DJ $ */
#endif
      return(TRUE);

    case KEY_ESC:
    case KEY_BREAK:
    case KEY_F10:
      ExitCode=(Key==KEY_BREAK) ? -2:-1;
      /* $ 18.05.2001 DJ */
      CloseDialog();
      /* DJ $ */
      return(TRUE);

    /* $ 04.12.2000 SVS
       3-� ��������� ���������
       ��� �������� ���� ������� ������ � ������, ���� �������
       ����� ���� DIF_3STATE
    */
    case KEY_ADD:
    case KEY_SUBTRACT:
    case KEY_MULTIPLY:
      if (Type==DI_CHECKBOX)
      {
        unsigned int CHKState=
           (Key == KEY_ADD?1:
            (Key == KEY_SUBTRACT?0:
             ((Key == KEY_MULTIPLY)?2:
              Item[FocusPos].Selected)));
        if(Item[FocusPos].Selected != CHKState)
          if(Dialog::SendDlgMessage((HANDLE)this,DN_BTNCLICK,FocusPos,CHKState))
          {
             Item[FocusPos].Selected=CHKState;
             ShowDialog();
          }
      }
      return(TRUE);
    /* SVS 22.11.2000 $ */

    case KEY_SPACE:
      if (Type==DI_BUTTON)
        return(ProcessKey(KEY_ENTER));
      if (Type==DI_CHECKBOX)
      {
        /* $ 04.12.2000 SVS
           3-� ��������� ���������
        */
        int OldSelected=Item[FocusPos].Selected;

        if(Item[FocusPos].Flags&DIF_3STATE)
          (++Item[FocusPos].Selected)%=3;
        else
          Item[FocusPos].Selected = !Item[FocusPos].Selected;
        /* $ 28.07.2000 SVS
          ��� ��������� ��������� ������� �������� �������� ���������
           ����������� ������� SendDlgMessage - � ��� �������� ���!
        */
        if(!Dialog::SendDlgMessage((HANDLE)this,DN_BTNCLICK,FocusPos,Item[FocusPos].Selected))
          Item[FocusPos].Selected = OldSelected;
        /* SVS $ */
        /* SVS 04.12.2000 $ */
        ShowDialog();
        return(TRUE);
      }
      if (Type==DI_RADIOBUTTON)
      {
        int PrevRB;
        for (I=FocusPos;;I--)
          if (Item[I].Type==DI_RADIOBUTTON && (Item[I].Flags & DIF_GROUP) ||
              I==0 || Item[I-1].Type!=DI_RADIOBUTTON)
            break;
        do
        {
          /* $ 28.07.2000 SVS
            ��� ��������� ��������� ������� �������� �������� ���������
            ����������� ������� SendDlgMessage - � ��� �������� ���!
          */
          J=Item[I].Selected;
          Item[I].Selected=0;
          if(J)
          {
            PrevRB=I;
          }
          ++I;
          /* SVS $ */
        } while (I<ItemCount && Item[I].Type==DI_RADIOBUTTON &&
                 (Item[I].Flags & DIF_GROUP)==0);

        Item[FocusPos].Selected=1;
        /* $ 28.07.2000 SVS
          ��� ��������� ��������� ������� �������� �������� ���������
          ����������� ������� SendDlgMessage - � ��� �������� ���!
        */
        if(!Dialog::SendDlgMessage((HANDLE)this,DN_BTNCLICK,PrevRB,0) ||
           !Dialog::SendDlgMessage((HANDLE)this,DN_BTNCLICK,FocusPos,1))
        {
           // ������ �����, ���� ������������ �� �������...
           Item[PrevRB].Selected=1;
           Item[FocusPos].Selected=0;
        }
        /* SVS $ */
        ShowDialog();
        return(TRUE);
      }
      if (IsEdit(Type) && !(Item[FocusPos].Flags & DIF_READONLY))
      {
        /* $ 28.07.2000 SVS
          ��� ��������� ��������� ������� �������� �������� ���������
          ����������� ������� SendDlgMessage - � ��� �������� ���!
        */
        if(((Edit *)(Item[FocusPos].ObjPtr))->ProcessKey(Key))
        {
          Dialog::SendDlgMessage((HANDLE)this,DN_EDITCHANGE,FocusPos,0);
          Redraw(); // ����������� ������ ���� ����� DN_EDITCHANGE (imho)
        }
        return(TRUE);
      }
      return(TRUE);

    case KEY_HOME:
      // ��� user-���� ����������
      if(Type == DI_USERCONTROL)
        return TRUE;

      if (IsEdit(Type))
      {
        ((Edit *)(Item[FocusPos].ObjPtr))->ProcessKey(Key);
        return(TRUE);
      }

      for (I=0;I<ItemCount;I++)
        if (IsFocused(Item[I].Type))
        {
          ChangeFocus2(FocusPos,I);
          /* $ 28.07.2000 SVS
            ��� ��������� ��������� ������� �������� �������� ���������
            ����������� ������� SendDlgMessage - � ��� �������� ���!
          */
          //Dialog::SendDlgMessage((HANDLE)this,DN_CHANGEITEM,FocusPos,0);
          //Dialog::SendDlgMessage((HANDLE)this,DN_CHANGEITEM,I,0);
          /* SVS $ */
          ShowDialog();
          return(TRUE);
        }
      return(TRUE);

    case KEY_LEFT:
    case KEY_RIGHT:
      // ��� user-���� ����������
      if(Type == DI_USERCONTROL)
        return TRUE;

      if (IsEdit(Type))
      {
        ((Edit *)(Item[FocusPos].ObjPtr))->ProcessKey(Key);
        return(TRUE);
      }
      {
        int MinDist=1000,MinPos;
        for (I=0;I<ItemCount;I++)
          if (I!=FocusPos && (IsEdit(Item[I].Type) || Item[I].Type==DI_CHECKBOX ||
              Item[I].Type==DI_RADIOBUTTON) && Item[I].Y1==Item[FocusPos].Y1)
          {
            int Dist=Item[I].X1-Item[FocusPos].X1;
            if (Key==KEY_LEFT && Dist<0 || Key==KEY_RIGHT && Dist>0)
              if (abs(Dist)<MinDist)
              {
                MinDist=abs(Dist);
                MinPos=I;
              }
          }
          if (MinDist<1000)
          {
            ChangeFocus2(FocusPos,MinPos);
            if (Item[MinPos].Flags & DIF_MOVESELECT)
              ProcessKey(KEY_SPACE);
            else
            {
              ShowDialog();
            }
            return(TRUE);
          }
      }

    case KEY_UP:
    case KEY_DOWN:
      // ��� user-���� ����������
      if(Type == DI_USERCONTROL)
        return TRUE;

      {
        int PrevPos=0;
        if (Item[FocusPos].Flags & DIF_EDITOR)
          PrevPos=((Edit *)(Item[FocusPos].ObjPtr))->GetCurPos();
        I=ChangeFocus(FocusPos,(Key==KEY_LEFT || Key==KEY_UP) ? -1:1,FALSE);
        Item[FocusPos].Focus=0;
        Item[I].Focus=1;
        ChangeFocus2(FocusPos,I);
        if (Item[I].Flags & DIF_EDITOR)
          ((Edit *)(Item[I].ObjPtr))->SetCurPos(PrevPos);
        if (Item[I].Flags & DIF_MOVESELECT)
          ProcessKey(KEY_SPACE);
        else
        {
          ShowDialog();
        }
      }
      return(TRUE);

    case KEY_END:
      // ��� user-���� ����������
      if(Type == DI_USERCONTROL)
        return TRUE;

      if (IsEdit(Type))
      {
        ((Edit *)(Item[FocusPos].ObjPtr))->ProcessKey(Key);
        return(TRUE);
      }
    case KEY_PGDN:
      // ��� user-���� ����������
      if(Type == DI_USERCONTROL)
        return TRUE;

      if (!(Item[FocusPos].Flags & DIF_EDITOR))
      {
        for (I=0;I<ItemCount;I++)
          if (Item[I].DefaultButton)
          {
            ChangeFocus2(FocusPos,I);
            ShowDialog();
            return(TRUE);
          }
      }
      else
      {
        ProcessKey(KEY_TAB);
        ProcessKey(KEY_UP);
      }
      return(TRUE);

    /* $ 27.04.2001 VVM
      + ��������� ������ ����� */
    case KEY_MSWHEEL_UP:
    case KEY_MSWHEEL_DOWN:
    /* VVM $ */
    case KEY_CTRLUP:
    case KEY_CTRLDOWN:
      // ��� user-���� ����������
      if(Type == DI_USERCONTROL)
        return TRUE;

      CurEditLine=((Edit *)(Item[FocusPos].ObjPtr));
      if (IsEdit(Type) &&
           (Item[FocusPos].Flags & DIF_HISTORY) &&
           Opt.DialogsEditHistory &&
           Item[FocusPos].History &&
           !(Item[FocusPos].Flags & DIF_READONLY))
      /* $ 26.07.2000 SVS
         �������� ��, ��� � ������ ����� � ������� ������ �� �������
         ��� ��������� ������� ������ � �������.
      */
      {
        char *PStr=Str;
        int MaxLen=sizeof(Item[FocusPos].Data);
        if(Item[FocusPos].Flags&DIF_VAREDIT)
        {
          MaxLen=Item[FocusPos].Ptr.PtrLength;
          if((PStr=(char*)malloc(MaxLen+1)) == NULL)
            return TRUE;//???
        }
        /* $ 27.04.2001 SVS
           ���%$@#&^%$&$%*%^$*^%$*^%$*^%$&*
           ����: sizeof(MaxLen) ;-( - ��� ���� ������ ������.
        */
        CurEditLine->GetString(PStr,MaxLen);
        /* SVS $ */
        SelectFromEditHistory(Item+FocusPos,CurEditLine,Item[FocusPos].History,PStr,MaxLen);
        if(Item[FocusPos].Flags&DIF_VAREDIT)
          free(PStr);
      }
      /* SVS $ */
      /* $ 18.07.2000 SVS
         + ��������� DI_COMBOBOX - ����� �� ������!
      */
      else if(Type == DI_COMBOBOX && Item[FocusPos].ListPtr &&
              !(Item[FocusPos].Flags & DIF_READONLY) &&
              Item[FocusPos].ListPtr->GetItemCount() > 0) //??
      {
        int MaxLen=(Item[FocusPos].Flags&DIF_VAREDIT)?
                     Item[FocusPos].Ptr.PtrLength:
                     sizeof(Item[FocusPos].Data);
        if(SelectFromComboBox(CurEditLine,Item[FocusPos].ListPtr,MaxLen) != KEY_ESC)
          Dialog::SendDlgMessage((HANDLE)this,DN_EDITCHANGE,FocusPos,0);
      }
      /* SVS $ */
      return(TRUE);

    default:
      // ��� user-���� ����������
      if(Type == DI_USERCONTROL)
        return TRUE;

      /* $ 01.08.2000 SVS
         ������� ListBox
      */
      if(Type == DI_LISTBOX)
      {
        Item[FocusPos].ListPtr->ProcessKey(Key);
        return(TRUE);
      }
      /* SVS $ */

      /* $ 21.08.2000 SVS
         Autocomplete ��� ���������� ������ � ������� ����������� ;-)
      */
      if (IsEdit(Type) && !(Item[FocusPos].Flags & DIF_READONLY))
      {
        Edit *edt=(Edit *)Item[FocusPos].ObjPtr;
        int SelStart, SelEnd;

        if(Key == KEY_CTRLL) // �������� ����� ������ RO ��� ���� ����� � ����������
          return TRUE;

        /* $ 11.09.2000 SVS
           Ctrl-U � ������� ����� ������� ������� �����
        */
        if(Key == KEY_CTRLU)
        {
          edt->SetClearFlag(0);
          edt->Select(-1,0);
          edt->Show();
          return TRUE;
        }
        /* SVS $ */

        if (Item[FocusPos].Flags & DIF_EDITOR)
          switch(Key)
          {
            /* $ 12.09.2000 SVS
              ���������� �������� � BackSpace � DIF_EDITOR
            */
            case KEY_BS:
            {
              int CurPos=edt->GetCurPos();
              /* $ 21.11.2000 SVS
                 �� ��������� ��������� ������ � ������������� ���������
              */
              // � ������ ������????
              if(!edt->GetCurPos())
              {
                // � "����" ���� DIF_EDITOR?
                if(FocusPos > 0 && (Item[FocusPos-1].Flags&DIF_EDITOR))
                {
                  // ��������� � ����������� �...
                  Edit *edt_1=(Edit *)Item[FocusPos-1].ObjPtr;
                  edt_1->GetString(Str,sizeof(Str));
                  CurPos=strlen(Str);
                  edt->GetString(Str+CurPos,sizeof(Str)-CurPos);
                  edt_1->SetString(Str);

                  for (I=FocusPos+1;I<ItemCount;I++)
                  {
                    if (Item[I].Flags & DIF_EDITOR)
                    {
                      if (I>FocusPos)
                      {
                        ((Edit *)(Item[I].ObjPtr))->GetString(Str,sizeof(Str));
                        ((Edit *)(Item[I-1].ObjPtr))->SetString(Str);
                      }
                      ((Edit *)(Item[I].ObjPtr))->SetString("");
                    }
                    else // ���, ������  FocusPos ��� ���� ��������� �� DIF_EDITOR
                    {
                      ((Edit *)(Item[I-1].ObjPtr))->SetString("");
                      break;
                    }
                  }
                  ProcessKey(KEY_UP);
                  edt_1->SetCurPos(CurPos);
                }
              }
              /* SVS $ */
              else
              {
                edt->ProcessKey(Key);
              }
              Dialog::SendDlgMessage((HANDLE)this,DN_EDITCHANGE,FocusPos,0);
              ShowDialog();
              return(TRUE);
            }
            /* SVS $ */

            case KEY_CTRLY:
              for (I=FocusPos;I<ItemCount;I++)
                if (Item[I].Flags & DIF_EDITOR)
                {
                  if (I>FocusPos)
                  {
                    ((Edit *)(Item[I].ObjPtr))->GetString(Str,sizeof(Str));
                    ((Edit *)(Item[I-1].ObjPtr))->SetString(Str);
                  }
                  ((Edit *)(Item[I].ObjPtr))->SetString("");
                }
                else
                  break;
              /* $ 28.07.2000 SVS
                ��� ��������� ��������� ������� �������� �������� ���������
                ����������� ������� SendDlgMessage - � ��� �������� ���!
              */
              Dialog::SendDlgMessage((HANDLE)this,DN_EDITCHANGE,FocusPos,0);
              /* SVS $ */
              ShowDialog();
              return(TRUE);

            case KEY_DEL:
              /* $ 19.07.2000 SVS
                 ! "...� ��������� ������ ���� ������� home shift+end del
                   ���� �� ���������..."
                   DEL � ������, ������� DIF_EDITOR, ������� ��� �����
                   ���������...
              */
              if (FocusPos<ItemCount+1 && (Item[FocusPos+1].Flags & DIF_EDITOR))
              {
                int CurPos=edt->GetCurPos();
                int Length=edt->GetLength();
                int SelStart, SelEnd;

                edt->GetSelection(SelStart, SelEnd);
                edt->GetString(Str,sizeof(Str));
                int LengthStr=strlen(Str);
                if(SelStart > -1)
                {
                  memmove(&Str[SelStart],&Str[SelEnd],Length-SelEnd+1);
                  edt->SetString(Str);
                  edt->SetCurPos(SelStart);
                  /* $ 28.07.2000 SVS
                    ��� ��������� ��������� ������� �������� �������� ���������
                    ����������� ������� SendDlgMessage - � ��� �������� ���!
                  */
                  Dialog::SendDlgMessage((HANDLE)this,DN_EDITCHANGE,FocusPos,0);
                  /* SVS $ */
                  ShowDialog();
                  return(TRUE);
                }
                else if (CurPos>=Length)
                {
                  Edit *edt_1=(Edit *)Item[FocusPos+1].ObjPtr;
                  /* $ 12.09.2000 SVS
                     ������ ��������, ���� Del ������ � �������
                     �������, ��� ����� ������
                  */
                  if (CurPos > Length)
                  {
                    LengthStr=CurPos;
                    memset(Str+Length,' ',CurPos-Length);
                  }
                  /* SVS $*/
                  edt_1->GetString(Str+LengthStr,sizeof(Str)-LengthStr);
                  edt_1->SetString(Str);
                  ProcessKey(KEY_CTRLY);
                  edt->SetCurPos(CurPos);
                  ShowDialog();
                  return(TRUE);
                }
              }
              break;
              /* SVS $*/
            case KEY_PGUP:
              ProcessKey(KEY_SHIFTTAB);
              ProcessKey(KEY_DOWN);
              return(TRUE);
          }

        /* $ 24.09.2000 SVS
           ����� ������� Xlat
        */
        /* $ 04.11.2000 SVS
           �������� �� �������������� �������
        */
        if((Opt.XLat.XLatDialogKey && Key == Opt.XLat.XLatDialogKey ||
           Opt.XLat.XLatAltDialogKey && Key == Opt.XLat.XLatAltDialogKey) ||
           Key == KEY_MACROXLAT)
        {
          edt->SetClearFlag(0);
          edt->Xlat();
          Dialog::SendDlgMessage((HANDLE)this,DN_EDITCHANGE,FocusPos,0);
          Redraw(); // ����������� ������ ���� ����� DN_EDITCHANGE (imho)
          return TRUE;
        }
        /* SVS $ */
        /* SVS $ */

        if (edt->ProcessKey(Key))
        {
          //int RedrawNeed=FALSE;
          /* $ 26.07.2000 SVS
             AutoComplite: ���� ���������� DIF_HISTORY
                 � ��������� ��������������!.
          */
          /* $ 04.12.2000 SVS
            �������������� - ����� �� �������� �� ����� ������������ ��������.
            GetCurRecord() ������ 0 ��� ������, ���� ��� �� ������ �� ���������.
          */
          if(!CtrlObject->Macro.GetCurRecord(NULL,NULL) &&
             ((Item[FocusPos].Flags & DIF_HISTORY) || Type == DI_COMBOBOX))
          if((Opt.AutoComplete && Key < 256 && Key != KEY_BS && Key != KEY_DEL) ||
             (!Opt.AutoComplete && Key == KEY_CTRLEND)
            )
          {
            /* $ 05.12.2000 IS
               ��� ������ � ������� ������ ;)
            */
            int MaxLen=sizeof(Item[FocusPos].Data);
            char *PStr=Str;
            if(Item[FocusPos].Flags & DIF_VAREDIT)
            {
              MaxLen=Item[FocusPos].Ptr.PtrLength;
              if((PStr=(char*)malloc(MaxLen+1)) == NULL)
                return TRUE; //???
            }
            int DoAutoComplete=TRUE;
            int CurPos=edt->GetCurPos();
            edt->GetString(PStr,MaxLen);
            int len=strlen(PStr);
            edt->GetSelection(SelStart,SelEnd);
            if(SelStart < 0 || SelStart==SelEnd)
                SelStart=len;
            else
                SelStart++;

            if(CurPos<SelStart) DoAutoComplete=FALSE;
            if(SelStart<SelEnd && SelEnd<len) DoAutoComplete=FALSE;

            if(Opt.EdOpt.PersistentBlocks)
            {
              if(DoAutoComplete && CurPos <= SelEnd)
              {
                PStr[CurPos]=0;
                edt->Select(CurPos,MaxLen); //select the appropriate text
                edt->DeleteBlock();
                edt->FastShow();
              }
            }
            /* IS $ */

            SelEnd=strlen(PStr);

            //find the string in the list
            /* $ 03.12.2000 IS
                 ��������� ���� DoAutoComplete
            */
            if (DoAutoComplete && FindInEditForAC(Type == DI_COMBOBOX,
                         (void *)Item[FocusPos].Selected,PStr,MaxLen))
            /* IS $ */
            {
//_D(SysLog("Coplete: Str=%s SelStart=%d SelEnd=%d CurPos=%d",Str,SelStart,SelEnd, CurPos));
              edt->SetString(PStr);
              edt->Select(SelEnd,MaxLen); //select the appropriate text
              //edt->Select(CurPos,sizeof(Str)); //select the appropriate text
              /* $ 01.08.2000 SVS
                 ��������� ������ � AutoComplete
              */
              edt->SetCurPos(CurPos); // SelEnd
              //RedrawNeed=TRUE;
            }
            if(Item[FocusPos].Flags & DIF_VAREDIT)
              free(PStr);
          }
          /* SVS 03.12.2000 $ */
          Dialog::SendDlgMessage((HANDLE)this,DN_EDITCHANGE,FocusPos,0);
          /* SVS $ */
//          if(RedrawNeed)
            Redraw(); // ����������� ������ ���� ����� DN_EDITCHANGE (imho)
          return(TRUE);
        }
        /* SVS 21.08.2000 $ */
      }

      if (ProcessHighlighting(Key,FocusPos,FALSE))
        return(TRUE);

      return(ProcessHighlighting(Key,FocusPos,TRUE));
  }
}


//////////////////////////////////////////////////////////////////////////
/* Public, Virtual:
   ��������� ������ �� "����".
   ����������� BaseInput::ProcessMouse.
*/
/* $ 18.08.2000 SVS
   + DN_MOUSECLICK
*/
int Dialog::ProcessMouse(MOUSE_EVENT_RECORD *MouseEvent)
{
  int I;
  int MsX,MsY;
  int Type;
  RECT Rect;

  /* $ 11.06.2001 KM
     ! ������� ���������� ������ ���� � DI_LISTBOX.
  */
  if(!DialogMode.Check(DMODE_SHOW))
    return FALSE;

  if(!DialogMode.Check(DMODE_MOUSEEVENT))
   if(!DlgProc((HANDLE)this,DN_MOUSEEVENT,0,(long)MouseEvent))
     return TRUE;

  MsX=MouseEvent->dwMousePosition.X;
  MsY=MouseEvent->dwMousePosition.Y;

  //for (I=0;I<ItemCount;I++)
  for (I=ItemCount-1;I>=0;I--)
  {
    if(Item[I].Flags&(DIF_DISABLE|DIF_HIDDEN))
      continue;
    Type=Item[I].Type;
    if (Type == DI_LISTBOX && MsY >= Y1+Item[I].Y1 &&
        MsY <= Y1+Item[I].Y2 && MsX <= X1+Item[I].X2)
    {
      /* $ 30.06.2001 KM */
      VMenu *List=Item[I].ListPtr;
      int Pos=List->GetSelectPos();
      if((MouseEvent->dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED))
      {
        if(FocusPos != I)
        {
          ChangeFocus2(FocusPos,I);
          ShowDialog();
        }

        if (!SendDlgMessage((HANDLE)this,DN_MOUSECLICK,I,(long)MouseEvent))
        {
          if (SendDlgMessage((HANDLE)this,DN_LISTCHANGE,I,(long)Pos))
          {
            if (MsX==X1+Item[I].X2 && MsY >= Y1+Item[I].Y1 && MsY <= Y1+Item[I].Y2)
              Item[I].ListPtr->ProcessMouse(MouseEvent); // ����� ��������� �� ���� �� �������� (KM)
            else
              ProcessKey(KEY_ENTER);
          }
        }
        return TRUE;
      }
      else
      {
        if (SendDlgMessage((HANDLE)this,DN_LISTCHANGE,I,(long)Pos))
          Item[I].ListPtr->ProcessMouse(MouseEvent);
      }
      /* KM $ */
      return(TRUE);
    }
  }
  /* KM $ */

  if (MouseEvent->dwButtonState==0)
    return(FALSE);

  if (MsX<X1 || MsY<Y1 || MsX>X2 || MsY>Y2)
  {
    if(!DlgProc((HANDLE)this,DN_MOUSECLICK,-1,(long)MouseEvent))
    {
      if (MouseEvent->dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
        ProcessKey(KEY_ESC);
      else if (MouseEvent->dwButtonState & RIGHTMOST_BUTTON_PRESSED)
        ProcessKey(KEY_ENTER);
    }
    return(TRUE);
  }

//_D(SysLog("Ms (%d,%d)",MsX,MsY));
  if (MouseEvent->dwEventFlags==0 || MouseEvent->dwEventFlags==DOUBLE_CLICK)
  {
    // ������ ���� - ��� �� ����������� �����.
    //for (I=0; I < ItemCount;I++)
    for (I=ItemCount-1;I>=0;I--)
    {
      if(Item[I].Flags&(DIF_DISABLE|DIF_HIDDEN))
        continue;

      GetItemRect(I,Rect);
      Rect.left+=X1;  Rect.top+=Y1;
      Rect.right+=X1; Rect.bottom+=Y1;
//_D(SysLog("? %2d) Rect (%2d,%2d) (%2d,%2d) '%s'",I,Rect.left,Rect.top,Rect.right,Rect.bottom,Item[I].Data));

      if(MsX >= Rect.left && MsY >= Rect.top && MsX <= Rect.right && MsY <= Rect.bottom)
      {
        // ��� ���������� :-)
        if(Item[I].Type == DI_SINGLEBOX || Item[I].Type == DI_DOUBLEBOX)
        {
          // ���� �� �����, ��...
          if(((MsX == Rect.left || MsX == Rect.right) && MsY >= Rect.top && MsY <= Rect.bottom) || // vert
             ((MsY == Rect.top  || MsY == Rect.bottom) && MsX >= Rect.left && MsX <= Rect.right) )   // hor
          {
            if(DlgProc((HANDLE)this,DN_MOUSECLICK,I,(long)MouseEvent))
              return TRUE;
          }
          else
            continue;
        }

        if(Item[I].Type == DI_USERCONTROL)
        {
          // ��� user-���� ���������� ���������� ����
          MouseEvent->dwMousePosition.X-=(short)Rect.left;
          MouseEvent->dwMousePosition.Y-=(short)Rect.top;
        }

//_SVS(SysLog("+ %2d) Rect (%2d,%2d) (%2d,%2d) '%s' Dbl=%d",I,Rect.left,Rect.top,Rect.right,Rect.bottom,Item[I].Data,MouseEvent->dwEventFlags==DOUBLE_CLICK));
        if(DlgProc((HANDLE)this,DN_MOUSECLICK,I,(long)MouseEvent))
          return TRUE;

        if(Item[I].Type == DI_USERCONTROL)
        {
           ChangeFocus2(FocusPos,I);
           ShowDialog();
           return(TRUE);
        }
        break;
      }
    }

    if((MouseEvent->dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED))
    {
      //for (I=0;I<ItemCount;I++)
      for (I=ItemCount-1;I>=0;I--)
      {
        /* $ 04.12.2000 SVS
           ��������� �� ������ ����������� � ���� ����������� ��������
        */
        if(Item[I].Flags&(DIF_DISABLE|DIF_HIDDEN))
          continue;
        /* SVS $ */
        Type=Item[I].Type;
        if (MsX>=X1+Item[I].X1)
        {
          if (IsEdit(Type))
          {
            /* $ 15.08.2000 SVS
               + ������� ���, ����� ����� ������ � DropDownList
                 ������ ����������� ���.
               ���� ��������� ���������� - ����� ������ ������� � ��
               ����� ������������ �� ������ �������, �� ������ �����������
               �� �������� ��������� �� ��������� ������� ������� �� ����������
            */
            int EditX1,EditY1,EditX2,EditY2;
            Edit *EditLine=(Edit *)(Item[I].ObjPtr);
            EditLine->GetPosition(EditX1,EditY1,EditX2,EditY2);

            if(MsY==EditY1 && Type == DI_COMBOBOX &&
               (Item[I].Flags & DIF_DROPDOWNLIST) &&
               MsX >= EditX1 && MsX <= EditX2+1)
            {
              EditLine->SetClearFlag(0);
              ChangeFocus2(FocusPos,I);
              ShowDialog();
              ProcessKey(KEY_CTRLDOWN);
              return(TRUE);
            }
            /* SVS $ */

            if (EditLine->ProcessMouse(MouseEvent))
            {
              EditLine->SetClearFlag(0); // � ����� ��� ������ � ����� edit?
              ChangeFocus2(FocusPos,I);
              /* $ 23.06.2001 KM
                 ! ��������� ����� �������������� ���� ������ �����
                   �� �������� ������� ���������� � ���������� � ������� ������.
              */
              ShowDialog(); // ����� �� ������ ���� ������� ��� ���� ������?
              /* KM $ */
              return(TRUE);
            }
            else
            {
              // �������� �� DI_COMBOBOX ����� ������. ������ (KM).
              if (MsX==EditX2+1 && MsY==EditY1 && Item[I].History &&
                  ((Item[I].Flags & DIF_HISTORY) && Opt.DialogsEditHistory))
              {
                EditLine->SetClearFlag(0); // ��� �� ���������� ��, �� �...
                ChangeFocus2(FocusPos,I);
                if(!(Item[I].Flags&DIF_HIDDEN))
                  ShowDialog(I);
                ProcessKey(KEY_CTRLDOWN);
                return(TRUE);
              }
            }
          }
          if (Type==DI_BUTTON &&
              MsY==Y1+Item[I].Y1 &&
              MsX < X1+Item[I].X1+HiStrlen(Item[I].Data))
          {
            ChangeFocus2(FocusPos,I);
            ShowDialog();
            while (IsMouseButtonPressed())
              ;
            if (MouseX <  X1 ||
                MouseX >  X1+Item[I].X1+HiStrlen(Item[I].Data)+4 ||
                MouseY != Y1+Item[I].Y1)
            {
              ChangeFocus2(FocusPos,I);
              ShowDialog();
              return(TRUE);
            }
            ProcessKey(KEY_ENTER);
            return(TRUE);
          }

          if ((Type == DI_CHECKBOX ||
               Type == DI_RADIOBUTTON) &&
              MsY==Y1+Item[I].Y1 &&
              MsX < (X1+Item[I].X1+HiStrlen(Item[I].Data)+4-((Item[I].Flags & DIF_MOVESELECT)!=0)))
          {
            ChangeFocus2(FocusPos,I);
            ProcessKey(KEY_SPACE);
            return(TRUE);
          }
        }
      } // for (I=0;I<ItemCount;I++)
      // ��� MOUSE-�����������:
      //   ���� �������� � ��� ������, ���� ���� �� ������ �� �������� ��������
      //
      /* $ 10.08.2000 SVS
         �������, ���� ���������! (IsCanMove)
      */
      if (DialogMode.Check(DMODE_ISCANMOVE) && DlgProc((HANDLE)this,DN_DRAGGED,0,0))
      {
        /* $ 03.08.2000 tran
           �� ��� �������� - �� ����� ���������� */
        //DialogMode.Set(DMODE_DRAGGED);
        OldX1=X1; OldX2=X2; OldY1=Y1; OldY2=Y2;
        // �������� delta ����� �������� � Left-Top ����������� ����
        MsX=abs(X1-MouseX);
        MsY=abs(Y1-MouseY);
        while (1)
        {
            int mb=IsMouseButtonPressed();
            /* $ 15.12.2000 SVS
               ����� ������ �������� �����������
            */
            int mx,my,X0,Y0;
            if ( mb==1 ) // left key, still dragging
            {
                Hide();
                X0=X1;
                Y0=Y1;
                if(MouseX==PrevMouseX)
                  mx=X1;
                else
                  mx=MouseX-MsX;
                if(MouseY==PrevMouseY)
                  my=Y1;
                else
                  my=MouseY-MsY;

                if(mx >= 0 && mx+(X2-X1)<=ScrX)
                {
                  X2=mx+(X2-X1);
                  X1=mx;
                  AdjustEditPos(X1-X0,0); //?
                }
                if(my >= 0 && my+(Y2-Y1)<=ScrY)
                {
                  Y2=my+(Y2-Y1);
                  Y1=my;
                  AdjustEditPos(0,Y1-Y0); //?
                }
                Show();
            }
            /* SVS $ */
            else if (mb==2) // right key, abort
            {
                Hide();
                AdjustEditPos(OldX1-X1,OldY1-Y1);
                X1=OldX1;
                X2=OldX2;
                Y1=OldY1;
                Y2=OldY2;
                DialogMode.Skip(DMODE_DRAGGED);
                DlgProc((HANDLE)this,DN_DRAGGED,1,TRUE);
                Show();
                break;
            }
            else  // release key, drop dialog
            {
                DialogMode.Skip(DMODE_DRAGGED);
                DlgProc((HANDLE)this,DN_DRAGGED,1,0);
                Show();
                break;
            }
        }// while (1)
        /* tran 03.08.2000 $ */
      }
      /* SVS 10.08.2000 $*/
    }
  }
  return(FALSE);
}
/* SVS 18.08.2000 $ */


//////////////////////////////////////////////////////////////////////////
/* Private:
   �������� ����� ����� (����������� ���������
     KEY_TAB, KEY_SHIFTTAB, KEY_UP, KEY_DOWN,
   � ��� �� Alt-HotKey)
*/
/* $ 28.07.2000 SVS
   ������� ��� ��������� DN_KILLFOCUS & DN_SETFOCUS
*/
/* $ 24.08.2000 SVS
   ������� ��� DI_USERCONTROL
*/
int Dialog::ChangeFocus(int FocusPos,int Step,int SkipGroup)
{
  int Type,OrigFocusPos=FocusPos;
//  int FucusPosNeed=-1;
  // � ������� ��������� ������� ����� �������� ���������,
  //   ��� ������� - LostFocus() - ������ ����� �����.
//  if(DialogMode.Check(DMODE_INITOBJECTS))
//    FucusPosNeed=DlgProc((HANDLE)this,DN_KILLFOCUS,FocusPos,0);
//  if(FucusPosNeed != -1 && IsFocused(Item[FucusPosNeed].Type))
//    FocusPos=FucusPosNeed;
//  else
  {
    while (1)
    {
      FocusPos+=Step;
      if (FocusPos>=ItemCount)
        FocusPos=0;
      if (FocusPos<0)
        FocusPos=ItemCount-1;

      Type=Item[FocusPos].Type;

      if(!(Item[FocusPos].Flags&(DIF_NOFOCUS|DIF_DISABLE|DIF_HIDDEN)))
      {
        if (Type==DI_LISTBOX || Type==DI_BUTTON || Type==DI_CHECKBOX || IsEdit(Type) || Type==DI_USERCONTROL)
          break;
        if (Type==DI_RADIOBUTTON && (!SkipGroup || Item[FocusPos].Selected))
          break;
      }
      // ������� ������������ � ����������� ����������� :-)
      if(OrigFocusPos == FocusPos)
        break;
    }
  }

//  Dialog::FocusPos=FocusPos;
  // � ������� ��������� ������� ����� �������� ���������,
  //   ��� ������� GotFocus() - ������� ����� �����.
  // ���������� ������������ �������� ������� ��������
//  if(DialogMode.Check(DMODE_INITOBJECTS))
//    DlgProc((HANDLE)this,DN_GOTFOCUS,FocusPos,0);
  return(FocusPos);
}
/* SVS $ */


//////////////////////////////////////////////////////////////////////////
/* $ 28.07.2000 SVS
   Private:
   �������� ����� ����� ����� ����� ����������.
   ������� �������� � ���, ����� ���������� DN_KILLFOCUS & DM_SETFOCUS
*/
int Dialog::ChangeFocus2(int KillFocusPos,int SetFocusPos)
{
  int FucusPosNeed=-1;
  if(!(Item[SetFocusPos].Flags&(DIF_NOFOCUS|DIF_DISABLE|DIF_HIDDEN)))
  {
    if(DialogMode.Check(DMODE_INITOBJECTS))
      FucusPosNeed=DlgProc((HANDLE)this,DN_KILLFOCUS,KillFocusPos,0);

    if(FucusPosNeed != -1 && IsFocused(Item[FucusPosNeed].Type))
      SetFocusPos=FucusPosNeed;

    if(Item[SetFocusPos].Flags&DIF_NOFOCUS)
       SetFocusPos=KillFocusPos;

    Item[KillFocusPos].Focus=0;
    Item[SetFocusPos].Focus=1;

    Dialog::PrevFocusPos=Dialog::FocusPos;
    Dialog::FocusPos=SetFocusPos;
    if(DialogMode.Check(DMODE_INITOBJECTS))
      DlgProc((HANDLE)this,DN_GOTFOCUS,SetFocusPos,0);
  }
  else
    SetFocusPos=KillFocusPos;

  SelectOnEntry(KillFocusPos,FALSE);
  SelectOnEntry(SetFocusPos,TRUE);
  return(SetFocusPos);
}
/* SVS $ */

/* $ 08.09.2000 SVS
  ������� SelectOnEntry - ��������� ������ ��������������
  ��������� ����� DIF_SELECTONENTRY
*/
void Dialog::SelectOnEntry(int Pos,BOOL Selected)
{
  if(IsEdit(Item[Pos].Type) &&
     (Item[Pos].Flags&DIF_SELECTONENTRY)
//     && PrevFocusPos != -1 && PrevFocusPos != Pos
    )
  {
    Edit *edt=(Edit *)Item[Pos].ObjPtr;
    if(edt)
    {
      if(Selected)
        edt->Select(0,edt->GetLength());
      else
        edt->Select(-1,0);
    }
  }
}
/* SVS $ */

/* $ 04.12.2000 SVS
   ! ����������� ������� ConvertItem() � DataToItem() - � �����������
     ����� ���������� ���������� � ������� ��� (MSVC - ��� ��� ������ :-(
*/

//////////////////////////////////////////////////////////////////////////
/* $ 28.07.2000 SVS
   Public, Static:
   + ������� ConvertItem - �������� �������������� ��������� ������� ��
   ����������� ������������� �� �������
*/
void Dialog::ConvertItem(int FromPlugin,
                         struct FarDialogItem *Item,struct DialogItem *Data,
                         int Count,BOOL InternalCall)
{
  int I;
  if(!Item || !Data)
    return;

  char *PtrData;
  int PtrLength;
  Edit *EditPtr;

  if(FromPlugin == CVTITEM_TOPLUGIN)
    for (I=0; I < Count; I++, ++Item, ++Data)
    {
      Item->Type=Data->Type;
      Item->X1=Data->X1;
      Item->Y1=Data->Y1;
      Item->X2=Data->X2;
      Item->Y2=Data->Y2;
      if(Item->X2 < Item->X1) Item->X2=Item->X1;
      if(Item->Y2 < Item->Y1) Item->Y2=Item->Y1;
      Item->Focus=Data->Focus;
      Item->Selected=Data->Selected;
      Item->Flags=Data->Flags;
      Item->DefaultButton=Data->DefaultButton;
      if(InternalCall)
      {
        if(Dialog::IsEdit(Data->Type) && (EditPtr=(Edit *)(Data->ObjPtr)) != NULL)
        {
          // �������� ��������
          if((Data->Type==DI_EDIT || Data->Type==DI_COMBOBOX) &&
             (Data->Flags&DIF_VAREDIT))
          {
            PtrData  =(char *)Data->Ptr.PtrData;
            PtrLength=Data->Ptr.PtrLength;
          }
          else
          {
            PtrData  =Data->Data;
            PtrLength=sizeof(Data->Data);
          }
          EditPtr->GetString(PtrData,PtrLength);
        }
      }
      memmove(Item->Data,Data->Data,sizeof(Item->Data));
    }
  else
    for (I=0; I < Count; I++, ++Item, ++Data)
    {
      Data->Type=Item->Type;
      Data->X1=Item->X1;
      Data->Y1=Item->Y1;
      Data->X2=Item->X2;
      Data->Y2=Item->Y2;
      if(Data->X2 < Data->X1) Data->X2=Data->X1;
      if(Data->Y2 < Data->Y1) Data->Y2=Data->Y1;
      Data->Focus=Item->Focus;
      Data->Selected=Item->Selected;
      Data->Flags=Item->Flags;
      Data->DefaultButton=Item->DefaultButton;
      memmove(Data->Data,Item->Data,sizeof(Data->Data));
      /* ���� ����� ����� �������� ����� ���������� ��������.
      �� �������� ������ ������ � ����� �� DN_EDITCHANGE
      if(InternalCall)
      {
        if(Dialog::IsEdit(Data->Type) && (EditPtr=(Edit *)(Data->ObjPtr)) != NULL)
        {
          // �������
          if((Data->Type==DI_EDIT || Data->Type==DI_COMBOBOX) &&
             (Data->Flags&DIF_VAREDIT))
          {
            PtrData  =(char *)Data->Ptr.PtrData;
            PtrLength=Data->Ptr.PtrLength;
          }
          else
          {
            PtrData  =Data->Data;
            PtrLength=sizeof(Data->Data);
          }
          EditPtr->SetString(PtrData);
        }
      }
      */
    }
}
/* SVS $ */

//////////////////////////////////////////////////////////////////////////
/* Public, Static:
   ����������� ������ �� ��������� ������� �� ����������
   �������������. ���������� ������� InitDialogItems (��. "Far PlugRinG
   Russian Help Encyclopedia of Developer")
*/
void Dialog::DataToItem(struct DialogData *Data,struct DialogItem *Item,int Count)
{
  int I;

  if(!Item || !Data)
    return;

  for (I=0; I < Count; I++, ++Item, ++Data)
  {
    Item->Type=Data->Type;
    Item->X1=Data->X1;
    Item->Y1=Data->Y1;
    Item->X2=Data->X2;
    Item->Y2=Data->Y2;
    if(Item->X2 < Item->X1) Item->X2=Item->X1;
    if(Item->Y2 < Item->Y1) Item->Y2=Item->Y1;
    Item->Focus=Data->Focus;
    Item->Selected=Data->Selected;
    Item->Flags=Data->Flags;
    Item->DefaultButton=Data->DefaultButton;
    if ((unsigned int)Data->Data<MAX_MSG)
      strcpy(Item->Data,MSG((unsigned int)Data->Data));
    else
      memcpy(Item->Data,Data->Data,sizeof(Item->Data));
    Item->ObjPtr=NULL;
    Item->ListPtr=NULL;
  }
}
/* SVS 04.12.2000 $ */


//////////////////////////////////////////////////////////////////////////
/* Private:
   ��������� ��� �������� ������� �� ������� ������ �����
   (DI_EDIT, DI_FIXEDIT, DI_PSWEDIT) � � ������ ������ ���������� TRUE
*/
/* $ 18.07.2000 SVS
   ! ������� DI_COMBOBOX ��������� � ��������� ��������� ����������...
*/
int Dialog::IsEdit(int Type)
{
  return(Type==DI_EDIT ||
         Type==DI_FIXEDIT ||
         Type==DI_PSWEDIT ||
         Type == DI_COMBOBOX);
}
/* SVS $ */


//////////////////////////////////////////////////////////////////////////
/* $ 28.07.2000 SVS
   �������, ������������ - "����� �� ������� ������� ����� ����� �����"
*/
/* $ 24.08.2000 SVS
   ������� ��� DI_USERCONTROL
*/
int Dialog::IsFocused(int Type)
{
  return(Type==DI_EDIT ||
         Type==DI_FIXEDIT ||
         Type==DI_PSWEDIT ||
         Type==DI_COMBOBOX ||
         Type==DI_BUTTON ||
         Type==DI_CHECKBOX ||
         Type==DI_RADIOBUTTON ||
         Type==DI_LISTBOX ||
         Type==DI_USERCONTROL);
}
/* 24.08.2000 SVS $ */
/* SVS $ */


//////////////////////////////////////////////////////////////////////////
/* $ 26.07.2000 SVS
   AutoComplite: ����� ��������� ��������� � �������
*/
/* $ 28.07.2000 SVS
   ! �������� Edit *EditLine ����� �������!
*/
int Dialog::FindInEditForAC(int TypeFind,void *HistoryName,char *FindStr,int MaxLen)
{
  char *Str;
  int I, LenFindStr=strlen(FindStr);

  if(!TypeFind)
  {
    char RegKey[NM];
    if((Str=(char*)malloc(MaxLen+1)) == NULL)
      return FALSE;
    sprintf(RegKey,fmtSavedDialogHistory,(char*)HistoryName);
    // �������� ������� �������
    for (I=0; I < HISTORY_COUNT; I++)
    {
      itoa(I,PHisLine,10);
      GetRegKey(RegKey,HisLine,Str,"",MaxLen);
      if (!LocalStrnicmp(Str,FindStr,LenFindStr))
        break;
    }
    if (I == HISTORY_COUNT)
    {
      free(Str);
      return FALSE;
    }
    /* $ 28.07.2000 SVS
       ��������� ������� �� �����������, � ��������� �����������.
    */
//_D(SysLog("FindInEditForAC()  FindStr=%s Str=%s",FindStr,&Str[strlen(FindStr)]));
    strncat(FindStr,&Str[LenFindStr],MaxLen-LenFindStr);
    /* SVS $ */
    free(Str);
  }
  else
  {
    struct FarListItem *ListItems=((struct FarList *)HistoryName)->Items;
    int Count=((struct FarList *)HistoryName)->ItemsNumber;

    for (I=0; I < Count ;I++)
    {
      if (!LocalStrnicmp(ListItems[I].Text,FindStr,Min(LenFindStr,(int)sizeof(ListItems[I].Text))))
        break;
    }
    if (I  == Count)
      return FALSE;

    if(sizeof(ListItems[I].Text) < LenFindStr)
      strncat(FindStr,&ListItems[I].Text[LenFindStr],MaxLen-LenFindStr);
  }
  return TRUE;
}
/*  SVS $ */

//////////////////////////////////////////////////////////////////////////
/* Private:
   ��������� ���������� ������ ��� ComboBox
*/
/*
   $ 18.07.2000 SVS
   �������-���������� ������ �� ������ � ���������...
*/
int Dialog::SelectFromComboBox(
         Edit *EditLine,                   // ������ ��������������
         VMenu *ComboBox,    // ������ �����
         int MaxLen)
{
  char *Str;
  int EditX1,EditY1,EditX2,EditY2;
  int I,Dest;

  if((Str=(char*)malloc(MaxLen)) != NULL)
  {
    EditLine->GetPosition(EditX1,EditY1,EditX2,EditY2);
    if (EditX2-EditX1<20)
      EditX2=EditX1+20;
    if (EditX2>ScrX)
      EditX2=ScrX;
    ComboBox->SetPosition(EditX1,EditY1+1,EditX2,0);
    // ����� ���������� ������� �� ��������� �������� ���������
    short Colors[VMENU_COLOR_COUNT];
    ComboBox->GetColors(Colors);
    if(DlgProc((HANDLE)this,DN_CTLCOLORDLGLIST,
                    sizeof(Colors)/sizeof(Colors[0]),(long)Colors))
      ComboBox->SetColors(Colors);

    SetDropDownOpened(TRUE); // ��������� ���� "��������" ����������.

    // �������� ��, ��� ���� � ������ �����!
    // if(EditLine->DropDownBox == 1) //???
    EditLine->GetString(Str,MaxLen);
    ComboBox->SetSelectPos(ComboBox->FindItem(0,Str,LIFIND_NOPATTERN),1);

    ComboBox->Show();

    Dest=ComboBox->GetSelectPos();
    while (!ComboBox->Done())
    {
      if (!GetDropDownOpened())
      {
        ComboBox->ProcessKey(KEY_ESC);
        continue;
      }
      //int Key=
      ComboBox->ReadInput();
      // ����� ����� �������� ���-�� ����, ��������,
      I=ComboBox->GetSelectPos();
      if(I != Dest)
      {
        if(!DlgProc((HANDLE)this,DN_LISTCHANGE,FocusPos,I))
          ComboBox->SetSelectPos(Dest,Dest<I?-1:1); //????
        else
          Dest=I;

#if 0
        // �� ����� ��������� �� DropDown ����� - ��������� ��� ���� �
        // ��������� ������
        // ��������!!!
        //  ����� ��������� �������!
        if(EditLine->DropDownBox == 1)
        {
          struct MenuItem *CurCBItem=ComboBox->GetItemPtr();
          EditLine->SetString(CurCBItem->Name);
          EditLine->Show();
          //EditLine->FastShow();
        }
#endif
      }
      // ��������� multiselect ComboBox
      // ...
      ComboBox->ProcessInput();
    }
    ComboBox->ClearDone();
    ComboBox->Hide();
    if (GetDropDownOpened()) // �������� �� ����������� ����?
      Dest=ComboBox->Modal::GetExitCode();
    else
      Dest=-1;
    SetDropDownOpened(FALSE); // ��������� ���� "��������" ����������.
    if (Dest<0)
    {
      free(Str);
      return KEY_ESC;
    }

    ComboBox->GetUserData(Str,MaxLen,Dest);
    EditLine->SetString(Str);
    EditLine->SetLeftPos(0);
    Redraw();
    free(Str);
    return KEY_ENTER;
  }
  return KEY_ESC;
}
/* SVS $ */

//////////////////////////////////////////////////////////////////////////
/* Private:
   ��������� ���������� ������ �� �������
*/
/* $ 26.07.2000 SVS
  + �������������� �������� � SelectFromEditHistory ��� ���������
   ������ ������� � ������� (���� ��� ������������� ������ �����)
*/
BOOL Dialog::SelectFromEditHistory(struct DialogItem *CurItem,
                                   Edit *EditLine,
                                   char *HistoryName,
                                   char *IStr,
                                   int MaxLen)
/* SVS $ */
/* $ 21.02.2001 IS
     ��������� �� ������ ������ (����������� �� � ����, �� ����������� ��!)
*/
{
  if(!EditLine)
    return FALSE;

  char RegKey[NM],Str[4096];
  int I,Dest,Ret=FALSE;
  int Locked;
  int IsOk=FALSE, Done, IsUpdate;
  struct MenuItem HistoryItem;
  int ItemsCount;
  int LastSelected = 0;
  int EditX1,EditY1,EditX2,EditY2;

  sprintf(RegKey,fmtSavedDialogHistory,HistoryName);
  {
    // �������� ������� ������������� ����
    VMenu HistoryMenu("",NULL,0,8,VMENU_ALWAYSSCROLLBAR);

    EditLine->GetPosition(EditX1,EditY1,EditX2,EditY2);
    if (EditX2-EditX1<20)
      EditX2=EditX1+20;
    if (EditX2>ScrX)
      EditX2=ScrX;

    HistoryMenu.SetFlags(VMENU_SHOWAMPERSAND);
    HistoryMenu.SetPosition(EditX1,EditY1+1,EditX2,0);
    HistoryMenu.SetBoxType(SHORT_SINGLE_BOX);

    SetDropDownOpened(TRUE); // ��������� ���� "��������" ����������.
    Done=FALSE;

    // �������� (��� ����������)
    CurItem->ListPtr=&HistoryMenu;

    while(!Done)
    {
      IsUpdate=FALSE;

      HistoryMenu.DeleteItems();

      // ���������� ������� ����
      for (ItemsCount=Dest=I=0; I < HISTORY_COUNT; I++)
      {
        memset(&HistoryItem,0,sizeof(HistoryItem));

        itoa(I,PHisLine,10);
        GetRegKey(RegKey,HisLine,Str,"",sizeof(Str));
        if (*Str==0)
          continue;

        itoa(I,PHisLocked,10);
        GetRegKey(RegKey,HisLocked,(int)Locked,0);
        HistoryItem.SetCheck(Locked);
        strncpy(HistoryItem.Name,Str,sizeof(HistoryItem.Name)-1);
        HistoryMenu.SetUserData(Str,0,
              HistoryMenu.AddItem(&HistoryItem));
        ItemsCount++;
      }
      if (ItemsCount==0)
        break;

      // �������� ��������
      Dest=Opt.DlgSelectFromHistory?HistoryMenu.FindItem(0,IStr,LIFIND_NOPATTERN):-1;
      HistoryMenu.SetSelectPos(Dest!=-1?Dest:0, 1);
      //  ����� ���������� ������� �� ��������� �������� ���������
      /*$ 14.06.2001 OT */
      short Colors[VMENU_COLOR_COUNT];
      /* OT $*/
      HistoryMenu.GetColors(Colors);
      if(DlgProc((HANDLE)this,DN_CTLCOLORDLGLIST,
                      sizeof(Colors)/sizeof(Colors[0]),(long)Colors))
        HistoryMenu.SetColors(Colors);
      HistoryMenu.Show();

      // �������� ���� ���������
      while (!HistoryMenu.Done())
      {
        if (!GetDropDownOpened())
        {
          Ret=FALSE;
          HistoryMenu.ProcessKey(KEY_ESC);
          Done=TRUE;
          continue;
        }

        int Key=HistoryMenu.ReadInput();

        if (Key==KEY_TAB) // Tab � ������ ������� - ������ Enter
        {
          HistoryMenu.ProcessKey(KEY_ENTER);
          Ret=TRUE;
          Done=TRUE;
          continue; //??
        }
        else if (Key==KEY_INS) // Ins �������� ����� ������� �� ��������.
        {
          itoa(HistoryMenu.GetSelectPos(),PHisLocked,10);
          if (!HistoryMenu.GetSelection())
          {
            HistoryMenu.SetSelection(TRUE);
            SetRegKey(RegKey,HisLocked,1);
          }
          else
          {
            HistoryMenu.SetSelection(FALSE);
            DeleteRegValue(RegKey,HisLocked);
          }
          HistoryMenu.SetUpdateRequired(TRUE);
          HistoryMenu.Redraw();
          continue;
        }
        else if (Key==KEY_SHIFTDEL) // Shift-Del ������� ������� ����� ������� ������.
        {
          LastSelected=HistoryMenu.GetSelectPos();
          if (!HistoryMenu.GetSelection(LastSelected))
          {
            HistoryMenu.Hide();
            // ������� �� ������� ���.
            for (I=0; I < HISTORY_COUNT;I++)
            {
              itoa(I,PHisLocked,10);
              DeleteRegValue(RegKey,HisLocked);
              itoa(I,PHisLine,10);
              DeleteRegValue(RegKey,HisLine);
            }
            // ������� �� ������ ������ ��, ��� ���������
            HistoryMenu.DeleteItem(LastSelected);
            // ���������� ������ � �������
            for (Dest=I=0; I < HistoryMenu.GetItemCount(); I++)
            {
               HistoryMenu.GetUserData(Str,sizeof(Str),I);
               itoa(Dest,PHisLine,10);
               SetRegKey(RegKey,HisLine,Str);
               if(HistoryMenu.GetSelection(I))
               {
                 itoa(Dest,PHisLocked,10);
                 SetRegKey(RegKey,HisLocked,TRUE);
               }
               Dest++;
            }

            HistoryMenu.SetUpdateRequired(TRUE);
            IsUpdate=TRUE;
            break;
          }
          continue;
        }
        else if (Key==KEY_DEL) // Del ������� ������� ������.
        {
          LastSelected=HistoryMenu.GetSelectPos();

          if (!Opt.Confirm.HistoryClear ||
              (Opt.Confirm.HistoryClear &&
               Message(MSG_WARNING,2,MSG(MHistoryTitle),
                       MSG(MHistoryClear),
                       MSG(MClear),MSG(MCancel))==0))
          {
            HistoryMenu.Hide();

            // ������� �� �������
            for (I=0; I < HISTORY_COUNT;I++)
            {
              itoa(I,PHisLocked,10);
              DeleteRegValue(RegKey,HisLocked);
              itoa(I,PHisLine,10);
              DeleteRegValue(RegKey,HisLine);
            } /* for */

            // ������� � ������
            for (Dest=I=0; I < HistoryMenu.GetItemCount(); I++)
            {
              if (HistoryMenu.GetSelection(I))
              {
                HistoryMenu.GetUserData(Str,sizeof(Str),I);
                itoa(Dest,PHisLine,10);
                SetRegKey(RegKey,HisLine,Str);
                itoa(Dest,PHisLocked,10);
                SetRegKey(RegKey,HisLocked,TRUE);
                Dest++;
              } /* if */
            } /* for */
          } /* if */
          HistoryMenu.SetUpdateRequired(TRUE);
          IsUpdate=TRUE;
          break;
        }

        // ���� ���� �������� DN_LISTCHANGE

        HistoryMenu.ProcessInput();
      }

      if(IsUpdate)
        continue;

      int ExitCode=HistoryMenu.Modal::GetExitCode();
      if (ExitCode<0)
      {
        Ret=FALSE;
        Done=TRUE;
//        break;
      }
      else
      {
        HistoryMenu.GetUserData(Str,Min((int)sizeof(Str),MaxLen),ExitCode);
        Ret=TRUE;
        Done=TRUE;
        IsOk=TRUE;
      }
    }

    // ������� (�� �����)
    CurItem->ListPtr=NULL;

    SetDropDownOpened(FALSE); // ��������� ���� "��������" ����������.
  }

  if(IsOk)
  {
    EditLine->SetString(Str);
    EditLine->SetLeftPos(0);
    Dialog::SendDlgMessage((HANDLE)this,DN_EDITCHANGE,FocusPos,0);
    Redraw();
  }
  return Ret;
}

//////////////////////////////////////////////////////////////////////////
/* Private:
   ������ � �������� - ���������� � reorder ������
*/
int Dialog::AddToEditHistory(char *AddStr,char *HistoryName)
{
#define MAXSIZESTRING 4096
  int AddLine=-1, I, J, Locked, HistCount, LockedCount=0;
  char Str[MAXSIZESTRING];
  char RegKey[NM];
  struct HistArray{
    char *Str;
    int  Locked;
  } His[HISTORY_COUNT],HisTemp[HISTORY_COUNT+1];

  sprintf(RegKey,fmtSavedDialogHistory,HistoryName);

  if (*AddStr==0)
  {
    SetRegKey(RegKey,"Flags",(DWORD)0);
    return FALSE;
  }

  memset(His,0,sizeof(His));
  memset(HisTemp,0,sizeof(HisTemp));

  // Read content & delete
  for (HistCount=I=0; I < HISTORY_COUNT; I++)
  {
    itoa(I,PHisLocked,10);
    GetRegKey(RegKey,HisLocked,Locked,0);
    itoa(I,PHisLine,10);
    GetRegKey(RegKey,HisLine,Str,"",sizeof(Str));

    if(*Str)
    {
      if((His[HistCount].Str=strdup(Str)) != NULL)
      {
        His[HistCount].Locked=Locked;
        LockedCount+=Locked;
        DeleteRegValue(RegKey,HisLocked);
        DeleteRegValue(RegKey,HisLine);
        ++HistCount;
      }
    }
  }

  // ���� ������ ����������
  for (I=0; I < HistCount; I++)
    if (!LCStricmp(AddStr,His[I].Str))
    {
      // ����� ������! ���� ������� ���� ���� ����������
      if(AddLine == -1 || AddLine != -1 && His[I].Locked)
        AddLine=I;
    }
  /*
    ����� � ���:
      ���� AddLine == -1, �� ����� ������ ���� � �������
      ���� LockedCount == HISTORY_COUNT, ��� ��������!
  */

  // � ����� �� ��������� ��?...
  if(LockedCount == HISTORY_COUNT && AddLine == -1)
    J=0;
  else // ...�� ������ �����, �� � �����!
  {
    // ��������� � ������ � ������ ������������
    HisTemp[0].Str=strdup(AddStr);
    HisTemp[0].Locked=(AddLine == -1)?0:His[AddLine].Locked;
    J=1;
  }

  // Locked ������
  for (I=0; I < HistCount; I++)
  {
    if(His[I].Locked && His[I].Str)
    {
      if(AddLine == I)
        continue;
      HisTemp[J].Str=His[I].Str;
      HisTemp[J].Locked=1;
      ++J;
    }
  }

  // UnLocked
  for (I=0; I < HistCount; I++)
  {
    if(!His[I].Locked && His[I].Str)
    {
      if(AddLine == I)
        continue;
      HisTemp[J].Str=His[I].Str;
      HisTemp[J].Locked=0;
      ++J;
    }
  }

  // ��������� ���������
  for (I=0; I < HISTORY_COUNT; I++)
  {
    if(HisTemp[I].Str)
    {
      // ����� ����� ������������
      for(J=I+1; J < HISTORY_COUNT; ++J)
      {
        if(HisTemp[J].Str)
        {
          if(!LCStricmp(HisTemp[I].Str,HisTemp[J].Str))
          {
            free(HisTemp[J].Str);
            HisTemp[J].Str=NULL;
          }
        }
      }
    }
  }
  // ����� � HisTemp ����� ��������������� ������

  // Save History
  for (J=I=0; I < HISTORY_COUNT; I++)
  {
    if(HisTemp[I].Str)
    {
      itoa(J,PHisLocked,10);
      itoa(J,PHisLine,10);
      SetRegKey(RegKey,HisLine,HisTemp[I].Str);
      if(HisTemp[I].Locked)
        SetRegKey(RegKey,HisLocked,HisTemp[I].Locked);
      free(HisTemp[I].Str);
      ++J;
    }
  }
  SetRegKey(RegKey,"Flags",1);
  return TRUE;
}


//////////////////////////////////////////////////////////////////////////
/* Public, Static:
   �������� �� HotKey
*/
/* $ 20.02.2001 SVS
   ��������� ��������� IsKeyHighlighted � ��������� Alt- ��
   ������� ��� ��������*/
int Dialog::IsKeyHighlighted(char *Str,int Key,int Translate,int AmpPos)
{
  if(AmpPos == -1)
  {
    if ((Str=strchr(Str,'&'))==NULL)
      return(FALSE);
    AmpPos=1;
  }
  else
  {
    if(AmpPos >= (int)strlen(Str))
      return FALSE;
    Str=Str+AmpPos;
    AmpPos=0;
    if(Str[AmpPos] == '&')
      AmpPos++;
  }
//_SVS(SysLog("'%s' (%d)",Str+AmpPos,AmpPos));
  int UpperStrKey=LocalUpper((int)Str[AmpPos]);
  /* $ 08.11.2000 SVS
     ������� �������� ����� ������ ��� hotkey (������������ ��������)
  */
  /* 28.12.2000 SVS
    + ��������� ��������� Opt.HotkeyRules */
  if (Key < 256)
  {
    int KeyToKey=LocalKeyToKey(Key);
    return(UpperStrKey == (int)LocalUpper(Key) ||
      Translate &&
      (!Opt.HotkeyRules && UpperStrKey==(int)LocalUpper(KeyToKey) ||
        Opt.HotkeyRules && LocalKeyToKey(UpperStrKey)==KeyToKey));
  }

  if(Key&KEY_ALT)
  {
    int AltKey=Key&(~KEY_ALT);
    if(AltKey < 256)
    {
      if (AltKey >= '0' && AltKey <= '9')
        return(AltKey==UpperStrKey);

      int AltKeyToKey=LocalKeyToKey(AltKey);
      if (AltKey > ' ' && AltKey <= 255)
  //         (AltKey=='-'  || AltKey=='/' || AltKey==','  || AltKey=='.' ||
  //          AltKey=='\\' || AltKey=='=' || AltKey=='['  || AltKey==']' ||
  //          AltKey==':'  || AltKey=='"' || AltKey=='~'))
      {
        return(UpperStrKey==(int)LocalUpper(AltKey) ||
               Translate &&
               (!Opt.HotkeyRules && UpperStrKey==(int)LocalUpper(AltKeyToKey) ||
                  Opt.HotkeyRules && LocalKeyToKey(UpperStrKey)==AltKeyToKey));
      }
    }
  }
  /* SVS $*/
  /* SVS $*/
  return(FALSE);
}
/* SVS $ */


//////////////////////////////////////////////////////////////////////////
/* Private:
   ���� �������� Alt-???
*/
int Dialog::ProcessHighlighting(int Key,int FocusPos,int Translate)
{
  int I, Type;
  DWORD Flags;
  for (I=0;I<ItemCount;I++)
  {
    Type=Item[I].Type;
    Flags=Item[I].Flags;

    if ((!IsEdit(Type) || (Type == DI_COMBOBOX && (Flags&DIF_DROPDOWNLIST))) &&
        (Flags & (DIF_SHOWAMPERSAND|DIF_DISABLE|DIF_HIDDEN))==0)
      if (IsKeyHighlighted(Item[I].Data,Key,Translate))
      {
        int DisableSelect=FALSE;

        // ���� ���: Edit(���� �������) � DI_TEXT � ���� ������, ��...
        if (I>0 &&
            Type==DI_TEXT &&                              // DI_TEXT
            IsEdit(Item[I-1].Type) &&                     // � ��������
            Item[I].Y1==Item[I-1].Y1 &&                   // � ��� � ���� ������
            (I+1 < ItemCount && Item[I].Y1!=Item[I+1].Y1)) // ...� ��������� ������� � ������ ������
        {
          if((Item[I-1].Flags&(DIF_DISABLE|DIF_HIDDEN)) != 0) // � �� ����������
             break;
          // ������� � ����������� ����� ��������� ��������� �������
          if(!DlgProc((HANDLE)this,DN_HOTKEY,I,Key))
            break; // ������� �� ���������� ���������...
          I=ChangeFocus(I,-1,FALSE);
          DisableSelect=TRUE;
        }
        else if (Item[I].Type==DI_TEXT      || Item[I].Type==DI_VTEXT ||
                 Item[I].Type==DI_SINGLEBOX || Item[I].Type==DI_DOUBLEBOX)
        {
          if(I+1 < ItemCount && // ...� ��������� �������
            (Item[I+1].Flags&(DIF_DISABLE|DIF_HIDDEN)) != 0) // � �� ����������
             break;
          // ������� � ����������� ����� ��������� ��������� �������
          if(!DlgProc((HANDLE)this,DN_HOTKEY,I,Key))
            break; // ������� �� ���������� ���������...
          I=ChangeFocus(I,1,FALSE);
          DisableSelect=TRUE;
        }
        /* $ 29.08.2000 SVS
           - ������ ����������� �����-��� - ������� ProcessHighlighting
           MY> ������ � ��������� ����� �������. � ���� � ���� ������� �������.
           MY> ������ � ��������� ���� ������, ���� Alt-������ ����� �
           MY> ��������� ������������� �����.

           � ������ ������ ���������� :-)))
        */
        // ������� � ����������� ����� ��������� ��������� �������
        if(!DlgProc((HANDLE)this,DN_HOTKEY,I,Key))
          break; // ������� �� ���������� ���������...
        ChangeFocus2(FocusPos,I);
        ShowDialog();
        /* SVS $ */
        if ((Item[I].Type==DI_CHECKBOX || Item[I].Type==DI_RADIOBUTTON) &&
            (!DisableSelect || (Item[I].Flags & DIF_MOVESELECT)))
        {
          ProcessKey(KEY_SPACE);
          return(TRUE);
        }
        else if (Item[I].Type==DI_BUTTON)
        {
          ProcessKey(KEY_ENTER);
          return(TRUE);
        }
        // ��� ComboBox`� - "����������" ��������� //????
        else if (Item[I].Type==DI_COMBOBOX)
        {
          ProcessKey(KEY_CTRLDOWN);
          return(TRUE);
        }
        return(TRUE);
      }
  }
  return(FALSE);
}


//////////////////////////////////////////////////////////////////////////
/* $ 31.07.2000 tran
   + ������� ������������� ��������� edit ������� */
/* $ 07.08.2000 SVS
   + � ��� ListBox ������?*/
void Dialog::AdjustEditPos(int dx, int dy)
{
  struct DialogItem *CurItem;
  int I;
  int x1,x2,y1,y2;

  if(!DialogMode.Check(DMODE_CREATEOBJECTS))
    return;

  ScreenObject *DialogScrObject;
  for (I=0; I < ItemCount; I++)
  {
    CurItem=&Item[I];
    int Type=CurItem->Type;
    if (CurItem->ObjPtr  && IsEdit(Type) ||
        CurItem->ListPtr && Type == DI_LISTBOX)
    {
       if(Type == DI_LISTBOX)
         DialogScrObject=(ScreenObject *)CurItem->ListPtr;
       else
         DialogScrObject=(ScreenObject *)CurItem->ObjPtr;
       DialogScrObject->GetPosition(x1,y1,x2,y2);
       x1+=dx;
       x2+=dx;
       y1+=dy;
       y2+=dy;
       DialogScrObject->SetPosition(x1,y1,x2,y2);
    }
  }
}
/* SVS $ */
/* tran 31.07.2000 $ */


//////////////////////////////////////////////////////////////////////////
/* $ 11.08.2000 SVS
   ������ � ���. ������� ���������� �������
   ���� ������� ����������� (����������)
*/
void Dialog::SetDialogData(long NewDataDialog)
{
  DataDialog=NewDataDialog;
}
/* SVS $ */

//////////////////////////////////////////////////////////////////////////
/* $ 11.08.2000 SVS
   + ��� ����, ����� ������� DM_CLOSE ����� �������������� Process
*/
void Dialog::Process()
{
  /* $ 17.05.2001 DJ
     NDZ
  */
  FrameManager->ExecuteModal (this);
  /* DJ $ */
}
/* SVS $ */

/* $ 18.05.2001 DJ */

void Dialog::CloseDialog()
{
  GetDialogObjectsData();
  if (DlgProc ((HANDLE)this,DM_CLOSE,ExitCode,0))
  {
    DialogMode.Set(DMODE_ENDLOOP);
    FrameManager->DeleteFrame (this);
  }
}

/* DJ $ */

/* $ 17.05.2001 DJ
   ��������� help topic'� � ������ �������, �������� ������������ ����
   �� Modal
*/

void Dialog::SetHelp (const char *Topic)
{
  if (HelpTopic)
    delete[] HelpTopic;
  HelpTopic=NULL;

  if(Topic && *Topic)
  {
    HelpTopic = new char [strlen (Topic)+1];
    if(HelpTopic)
      strcpy (HelpTopic, Topic);
  }
}

void Dialog::ShowHelp()
{
  if (HelpTopic && *HelpTopic)
  {
    Help Hlp (HelpTopic);
  }
}

void Dialog::ClearDone()
{
  DialogMode.Skip(DMODE_ENDLOOP);
}

void Dialog::SetExitCode(int Code)
{
  ExitCode=Code;
  DialogMode.Set(DMODE_ENDLOOP);
  //CloseDialog();
}

/* DJ $ */

/* $ 19.05.2001 DJ
   ���������� ���� �������� ��� ���� �� F12
*/

int Dialog::GetTypeAndName (char *Type, char *Name)
{
  strcpy (Type, MSG(MDialogType));
  strcpy (Name, GetDialogTitle());
  return MODALTYPE_DIALOG;
}

/* DJ $ */

int Dialog::GetMacroMode()
{
  return MACRO_DIALOG;
}

int Dialog::FastHide()
{
  return Opt.AllCtrlAltShiftRule & CASR_DIALOG;
}

void Dialog::ResizeConsole()
{
  COORD c;
  DialogMode.Set(DMODE_RESIZED);
  Hide();
  // ��������� �������������� ��������� ������� (����� �� ������������ :-)
  c.X=ScrX+1; c.Y=ScrY+1;
  Dialog::SendDlgMessage((HANDLE)this,DN_RESIZECONSOLE,0,(long)&c);

  // !!!!!!!!!!! ����� ����� ��������� ��������� ��������� !!!!!!!!!!!
  //c.X=((X1*100/PrevScrX)*ScrX)/100;
  //c.Y=((Y1*100/PrevScrY)*ScrY)/100;
  // !!!!!!!!!!! ����� ����� ��������� ��������� ��������� !!!!!!!!!!!
  c.X=c.Y=-1;
  Dialog::SendDlgMessage((HANDLE)this,DM_MOVEDIALOG,TRUE,(long)&c);
};

void Dialog::OnDestroy()
{
  if(DialogMode.Check(DMODE_RESIZED))
  {
    FrameManager->GetBottomFrame()->UnlockRefresh();
    Dialog::SendDlgMessage((HANDLE)this,DM_KILLSAVESCREEN,0,0);
  }
};

//////////////////////////////////////////////////////////////////////////
/* $ 28.07.2000 SVS
   ������� ��������� ������� (�� ���������)
   ��� ������ ��� ������� � �������� ��������� ������� ��������� �������.
   �.�. ����� ������ ���� ��� ��������� ���� ���������!!!
*/
/* $ 02.07.2001 KM
   - ��������� �� �������������� (� ������� �� ������) ����
     ��� Param1==-1.
*/
#if defined(SYSLOG_DIALOG)
#define DEF_MESSAGE(m) { m , #m }
const char *MsgToName(int Msg)
{
  static struct MsgName{
    int Msg;
    const char *Name;
  } Message[]={
    DEF_MESSAGE(DM_FIRST),             DEF_MESSAGE(DM_CLOSE),
    DEF_MESSAGE(DM_ENABLE),            DEF_MESSAGE(DM_ENABLEREDRAW),
    DEF_MESSAGE(DM_GETDLGDATA),        DEF_MESSAGE(DM_GETDLGITEM),
    DEF_MESSAGE(DM_GETDLGRECT),        DEF_MESSAGE(DM_GETTEXT),
    DEF_MESSAGE(DM_GETTEXTLENGTH),     DEF_MESSAGE(DM_KEY),
    DEF_MESSAGE(DM_MOVEDIALOG),        DEF_MESSAGE(DM_SETDLGDATA),
    DEF_MESSAGE(DM_SETDLGITEM),        DEF_MESSAGE(DM_SETFOCUS),
    DEF_MESSAGE(DM_SETREDRAW),         DEF_MESSAGE(DM_SETTEXT),
    DEF_MESSAGE(DM_SETTEXTLENGTH),     DEF_MESSAGE(DM_SHOWDIALOG),
    DEF_MESSAGE(DM_GETFOCUS),          DEF_MESSAGE(DM_GETCURSORPOS),
    DEF_MESSAGE(DM_SETCURSORPOS),      DEF_MESSAGE(DM_GETTEXTPTR),
    DEF_MESSAGE(DM_SETTEXTPTR),        DEF_MESSAGE(DM_SHOWITEM),
    DEF_MESSAGE(DM_ADDHISTORY),        DEF_MESSAGE(DM_GETCHECK),
    DEF_MESSAGE(DM_SETCHECK),          DEF_MESSAGE(DM_SET3STATE),
    DEF_MESSAGE(DM_LISTSORT),          DEF_MESSAGE(DM_LISTGET),
    DEF_MESSAGE(DM_LISTGETCURPOS),     DEF_MESSAGE(DM_LISTSETCURPOS),
    DEF_MESSAGE(DM_LISTDELETE),        DEF_MESSAGE(DM_LISTADD),
    DEF_MESSAGE(DM_LISTADDSTR),        DEF_MESSAGE(DM_LISTUPDATE),
    DEF_MESSAGE(DM_LISTINSERT),        DEF_MESSAGE(DM_LISTFINDSTRING),
    DEF_MESSAGE(DM_LISTINFO),          DEF_MESSAGE(DM_LISTGETDATA),
    DEF_MESSAGE(DM_LISTSETDATA),       DEF_MESSAGE(DM_LISTSETTITLES),
    DEF_MESSAGE(DM_LISTGETTITLES),     DEF_MESSAGE(DM_RESIZEDIALOG),
    DEF_MESSAGE(DM_SETITEMPOSITION),   DEF_MESSAGE(DM_GETDROPDOWNOPENED),
    DEF_MESSAGE(DM_SETDROPDOWNOPENED), DEF_MESSAGE(DM_SETHISTORY),
    DEF_MESSAGE(DM_GETITEMPOSITION),   DEF_MESSAGE(DM_SETMOUSEEVENTNOTIFY),
    DEF_MESSAGE(DN_FIRST),             DEF_MESSAGE(DN_BTNCLICK),
    DEF_MESSAGE(DN_CTLCOLORDIALOG),    DEF_MESSAGE(DN_CTLCOLORDLGITEM),
    DEF_MESSAGE(DN_CTLCOLORDLGLIST),   DEF_MESSAGE(DN_DRAWDIALOG),
    DEF_MESSAGE(DN_DRAWDLGITEM),       DEF_MESSAGE(DN_EDITCHANGE),
    DEF_MESSAGE(DN_ENTERIDLE),         DEF_MESSAGE(DN_GOTFOCUS),
    DEF_MESSAGE(DN_HELP),              DEF_MESSAGE(DN_HOTKEY),
    DEF_MESSAGE(DN_INITDIALOG),        DEF_MESSAGE(DN_KILLFOCUS),
    DEF_MESSAGE(DN_LISTCHANGE),        DEF_MESSAGE(DN_MOUSECLICK),
    DEF_MESSAGE(DN_DRAGGED),           DEF_MESSAGE(DN_RESIZECONSOLE),
    DEF_MESSAGE(DN_MOUSEEVENT),        DEF_MESSAGE(DN_CLOSE),
    DEF_MESSAGE(DN_KEY),               DEF_MESSAGE(DM_USER),
    DEF_MESSAGE(DM_KILLSAVESCREEN),    DEF_MESSAGE(DM_ALLKEYMODE),
  };
  int I;
  for(I=0; I < sizeof(Message)/sizeof(Message[0]); ++I)
    if(Message[I].Msg == Msg)
      return Message[I].Name;
  return "";
}
#endif

long WINAPI Dialog::DefDlgProc(HANDLE hDlg,int Msg,int Param1,long Param2)
{
  Dialog* Dlg=(Dialog*)hDlg;
  struct DialogItem *CurItem=NULL;
  char *Ptr=NULL;
  int Type=0;
  _DIALOG(CleverSysLog CL("Dialog::DefDlgProc()"));
  _DIALOG(SysLog("hDlg=%p, Msg=%d (%s), Param1=%d, Param2=0x%08X",hDlg,Msg,MsgToName(Msg),Param1,Param2));
  if(!Dlg)
    return 0;

  switch(Msg)
  {
    case DN_INITDIALOG:
      return FALSE; // ��������� �� ����!

    case DM_CLOSE:
      return TRUE;  // �������� � ���������

    case DN_KILLFOCUS:
      return -1;    // "�������� � ������� ������"

    case DN_GOTFOCUS:
      return 0;     // always 0

    case DN_HELP:
      return Param2; // ��� ��������, �� �...

    case DN_DRAGGED:
      return TRUE; // �������� � ������������.

    case DN_DRAWDIALOG:
    {
      if(Param1 == 1)  // ����� ���������� "�������"?
      {
        /* $ 03.08.2000 tran
           ����� ������ � ���� ����� ��������� � ������� �����������
           1) ����� ������ ������������ � ����
           2) ����� ������ ������������ �� ����
           ������ ����� ������� ������� �� ����� */
        Text(Dlg->X1,Dlg->Y1,0xCE,"\\");
        Text(Dlg->X1,Dlg->Y2,0xCE,"/");
        Text(Dlg->X2,Dlg->Y1,0xCE,"/");
        Text(Dlg->X2,Dlg->Y2,0xCE,"\\");
      }
      return TRUE;
    }

    case DN_CTLCOLORDIALOG:
      return Param2;

    case DN_CTLCOLORDLGITEM:
      return Param2;

    case DN_CTLCOLORDLGLIST:
      return FALSE;

    case DN_ENTERIDLE:
      return 0;     // always 0
  }

  // �������������� ��������...
  if(Param1 >= Dlg->ItemCount && Dlg->Item)
    return 0;

  if (Param1>=0)
  {
    CurItem=&Dlg->Item[Param1];
    Type=CurItem->Type;
    Ptr=CurItem->Data;
  }

  switch(Msg)
  {
    case DN_MOUSECLICK:
      return FALSE;

    case DN_DRAWDLGITEM:
      return TRUE;

    case DN_HOTKEY:
      return TRUE;

    case DN_EDITCHANGE:
      return TRUE;

    case DN_BTNCLICK:
      return ((Type==DI_BUTTON)?FALSE:TRUE);

    case DN_LISTCHANGE:
      return TRUE;

    /* $ 23.08.2000 SVS
       + �������� �������(�)
    */
    case DM_KEY:
      return FALSE;
    /* SVS $ */

    case DN_MOUSEEVENT:
      return TRUE;
  }

  return 0;
}
/* SVS $ */


//////////////////////////////////////////////////////////////////////////
/* $ 28.07.2000 SVS
   ������� ��������� �������
   ��������� ��������� ��� ������� ������������ ����, �� ��������� ����������
   ����������� �������.
*/
/* $ 02.07.2001 KM
   - ��������� �� �������������� (� ������� �� ������) ����
     ��� Param1==-1.
*/
long WINAPI Dialog::SendDlgMessage(HANDLE hDlg,int Msg,int Param1,long Param2)
{
  Dialog* Dlg=(Dialog*)hDlg;
  struct DialogItem *CurItem=NULL;
  int Type=0;
  char *Ptr=NULL;
  char Str[1024];
  int Len, I;
  struct FarDialogItem PluginDialogItem;

  _DIALOG(CleverSysLog CL("Dialog::SendDlgMessage()"));
  _DIALOG(SysLog("hDlg=%p, Msg=%d (%s), Param1=%d, Param2=0x%08X",hDlg,Msg,MsgToName(Msg),Param1,Param2));

  if(!Dlg)
    return 0;
  // �������������� ��������...
  if(Param1 >= Dlg->ItemCount || !Dlg->Item)
    return 0;

//  CurItem=&Dlg->Item[Param1];
  if (Param1>=0)
  {
    CurItem=Dlg->Item+Param1;
    Type=CurItem->Type;
    Ptr=CurItem->Data;
  }

  switch(Msg)
  {
    case DM_LISTSORT: // Param1=ID Param=Direct {0|1}
    case DM_LISTADD: // Param1=ID Param2=FarList: ItemsNumber=Count, Items=Src
    case DM_LISTADDSTR: // Param1=ID Param2=String
    case DM_LISTDELETE: // Param1=ID Param2=FarListDelete: StartIndex=BeginIndex, Count=���������� (<=0 - ���!)
    case DM_LISTGET: // Param1=ID Param2=FarList: ItemsNumber=Index, Items=Dest
    case DM_LISTGETCURPOS: // Param1=ID Param2=FarListPos
    case DM_LISTSETCURPOS: // Param1=ID Param2=FarListPos Ret: RealPos
    case DM_LISTUPDATE: // Param1=ID Param2=FarList: ItemsNumber=Index, Items=Src
    case DM_LISTINFO:// Param1=ID Param2=FarListInfo
    case DM_LISTFINDSTRING: // Param1=ID Param2=FarListFind
    case DM_LISTINSERT: // Param1=ID Param2=FarListInsert
    case DM_LISTGETDATA: // Param1=ID Param2=Index
    case DM_LISTSETDATA: // Param1=ID Param2=struct FarListItemData
    case DM_LISTSETTITLES: // Param1=ID Param2=struct FarListTitles: TitleLen=strlen(Title), BottomLen=strlen(Bottom)
    case DM_LISTGETTITLES: // Param1=ID Param2=struct FarListTitles: TitleLen=strlen(Title), BottomLen=strlen(Bottom)
      if(Type==DI_LISTBOX || Type==DI_COMBOBOX)
      {
        VMenu *ListBox;
        ListBox=CurItem->ListPtr;
        if(ListBox)
        {
          int Ret=TRUE;
          switch(Msg)
          {
            case DM_LISTFINDSTRING: // Param1=ID Param2=FarListFind
            {
              return ListBox->FindItem(((struct FarListFind *)Param2)->StartIndex,
                                       ((struct FarListFind *)Param2)->Pattern,
                                       ((struct FarListFind *)Param2)->Flags);
            }

            case DM_LISTINSERT: // Param1=ID Param2=FarListInsert
            {
              if((Ret=ListBox->InsertItem((struct FarListInsert *)Param2)) == -1)
                return -1;
              break;
            }
            case DM_LISTINFO:// Param1=ID Param2=FarListInfo
            {
              return ListBox->GetVMenuInfo((struct FarListInfo*)Param2);
            }
            case DM_LISTSORT: // Param1=ID Param=Direct {0|1}
            {
              ListBox->SortItems(Param2);
              break;
            }
            case DM_LISTADDSTR: // Param1=ID Param2=String
            {
              Ret=ListBox->AddItem((char*)Param2);
              break;
            }
            case DM_LISTADD: // Param1=ID Param2=FarList: ItemsNumber=Count, Items=Src
            {
              struct FarList *ListItems=(struct FarList *)Param2;
              if(!ListItems)
                return FALSE;
              Ret=ListBox->AddItem(ListItems);
              break;
            }
            case DM_LISTDELETE: // Param1=ID Param2=FarListDelete: StartIndex=BeginIndex, Count=���������� (<=0 - ���!)
            {
              int Count;
              struct FarListDelete *ListItems=(struct FarListDelete *)Param2;
              if(!ListItems || (Count=ListItems->Count) <= 0)
                ListBox->DeleteItems();
              else
                ListBox->DeleteItem(ListItems->StartIndex,Count);
              break;
            }
            case DM_LISTGETDATA: // Param1=ID Param2=Index
            {
              if(Param2 < ListBox->GetItemCount())
                return (long)ListBox->GetUserData(NULL,0,Param2);
              return NULL;
            }

            case DM_LISTSETDATA: // Param1=ID Param2=struct FarListItemData
            {
              struct FarListItemData *ListItems=(struct FarListItemData *)Param2;
              if(ListItems &&
                 ListItems->Index < ListBox->GetItemCount())
              {
                  return ListBox->SetUserData(ListItems->Data,
                                              ListItems->DataSize,
                                              ListItems->Index);
              }
              return 0;
            }
            case DM_LISTSETTITLES: // Param1=ID Param2=struct FarListTitles
            {
              struct FarListTitles *ListTitle=(struct FarListTitles *)Param2;
              ListBox->SetTitle((!ListTitle)?NULL:ListTitle->Title);
              ListBox->SetBottomTitle((!ListTitle)?NULL:ListTitle->Bottom);
              return TRUE;
            }
            case DM_LISTGETTITLES: // Param1=ID Param2=struct FarListTitles
            {
              struct FarListTitles *ListTitle=(struct FarListTitles *)Param2;
              if(ListTitle)
              {
                if (ListBox->GetTitle(ListTitle->Title,ListTitle->TitleLen) ||
                    ListBox->GetTitle(ListTitle->Bottom,ListTitle->BottomLen))
                  return TRUE;
              }
              return FALSE;
            }
            case DM_LISTGETCURPOS: // Param1=ID Param2=FarListPos
            {
              if (Param2)
                return ListBox->GetSelectPos((struct FarListPos *)Param2);
              else
                return ListBox->GetSelectPos();
            }
            case DM_LISTSETCURPOS: // Param1=ID Param2=FarListPos Ret: RealPos
            {
              /* 26.06.2001 KM ������� ����� ���������� ������� �� ���� ��������� */
              int CurListPos=ListBox->GetSelectPos();
              Ret=ListBox->SetSelectPos((struct FarListPos *)Param2);
              if(Ret!=CurListPos)
                if(!Dlg->DlgProc(hDlg,DN_LISTCHANGE,Param1,Ret))
                  Ret=ListBox->SetSelectPos(CurListPos,1);
              /* KM $ */
              break; // �.�. ����� ������������!
            }
            case DM_LISTUPDATE: // Param1=ID Param2=FarList: Index=Index, Items=Src
            {
              if(Param2 && ListBox->UpdateItem((struct FarList *)Param2))
                break;
              return FALSE;
            }
            case DM_LISTGET: // Param1=ID Param2=FarList: ItemsNumber=Index, Items=Dest
            {
              struct FarList *ListItems=(struct FarList *)Param2;
              if(!ListItems)
                return FALSE;
              struct MenuItem *ListMenuItem;
              if((ListMenuItem=ListBox->GetItemPtr(ListItems->ItemsNumber)) != NULL)
              {
                ListItems->ItemsNumber=1;
                struct FarListItem *Items=ListItems->Items;
                if(Items)
                {
                  memset(Items,0,sizeof(struct FarListItem));
                  Items->Flags=ListMenuItem->Flags;
                  strncpy(Items->Text,ListMenuItem->Name,sizeof(Items->Text)-1);
                  return TRUE;
                }
              }
              return FALSE;
            }
            //case DM_LISTINS: // Param1=ID Param2=FarList: ItemsNumber=Index, Items=Dest
          }
          if(Dlg->DialogMode.Check(DMODE_SHOW) && ListBox->UpdateRequired())
          {
            Dlg->ShowDialog(Param1);
            ScrBuf.Flush();
          }
          return Ret;
        }
      }
      return FALSE;

    case DM_SETHISTORY: // Param1 = ID, Param2 = LPSTR HistoryName
    {
      if(Type==DI_EDIT || Type==DI_FIXEDIT)
      {
        if(Param2 && *(char *)Param2)
        {
          CurItem->Flags|=DIF_HISTORY;
          CurItem->History=(char *)Param2;
        }
        else
        {
          CurItem->Flags&=~DIF_HISTORY;
          CurItem->History=NULL;
        }
        Dlg->ShowDialog(Param1);
        ScrBuf.Flush();
        return TRUE;
      }
      return FALSE;
    }

    case DM_ADDHISTORY:
      if(Param2 &&
         (Type==DI_EDIT || Type==DI_FIXEDIT) &&
         (CurItem->Flags & DIF_HISTORY))
      {
        return Dlg->AddToEditHistory((char*)Param2,CurItem->History);
      }
      return FALSE;
    /* $ 23.10.2000 SVS
       ��������/���������� ������� � ������� ��������������
    */
    case DM_GETCURSORPOS:
      if(!CurItem->ObjPtr || !Param2)
        return FALSE;
      if (IsEdit(Type))
      {
        ((COORD*)Param2)->X=((Edit *)(CurItem->ObjPtr))->GetCurPos();
        ((COORD*)Param2)->Y=0;
        return TRUE;
      }
      else if(Type == DI_USERCONTROL)
      {
        ((COORD*)Param2)->X=((COORD*)(CurItem->ObjPtr))->X;
        ((COORD*)Param2)->Y=((COORD*)(CurItem->ObjPtr))->Y;
        return TRUE;
      }
      return FALSE;

    case DM_SETCURSORPOS:
      if(!CurItem->ObjPtr)
        return FALSE;
      if (IsEdit(Type))
      {
        ((Edit *)(CurItem->ObjPtr))->SetCurPos(((COORD*)Param2)->X);
        return TRUE;
      }
      else if(Type == DI_USERCONTROL)
      {
        // �����, ��� ���������� ��� ����� �������� ������ �������������!
        //  � ���������� � 0,0
        COORD Coord=*(COORD*)Param2;
        Coord.X+=CurItem->X1;
        if(Coord.X > CurItem->X2)
          Coord.X=CurItem->X2;

        Coord.Y+=CurItem->Y1;
        if(Coord.Y > CurItem->Y2)
          Coord.Y=CurItem->Y2;

        // ��������
        ((COORD*)(CurItem->ObjPtr))->X=Coord.X-CurItem->X1;
        ((COORD*)(CurItem->ObjPtr))->Y=Coord.Y-CurItem->Y1;
        // ���������� ���� ����
        if(Dlg->DialogMode.Check(DMODE_SHOW) && Dlg->FocusPos == Param1)
        {
           // ���-�� ���� ���� ������ :-)
           MoveCursor(Coord.X+Dlg->X1,Coord.Y+Dlg->Y1); // ???
           Dlg->ShowDialog(); //???
        }
        return TRUE;
      }
      return FALSE;
    /* SVS $ */


    case DN_LISTCHANGE:
    {
      return Dlg->DlgProc(hDlg,Msg,Param1,Param2);
    }

    case DN_EDITCHANGE:
    {
      Dialog::ConvertItem(CVTITEM_TOPLUGIN,&PluginDialogItem,CurItem,1,TRUE);
      if((I=Dlg->DlgProc(hDlg,Msg,Param1,(long)&PluginDialogItem)) == TRUE)
        Dialog::ConvertItem(CVTITEM_FROMPLUGIN,&PluginDialogItem,CurItem,1,TRUE);
      return I;
    }

    case DN_BTNCLICK:
      return Dlg->DlgProc(hDlg,Msg,Param1,Param2);

    case DM_GETCHECK:
      if(Type == DI_CHECKBOX || Type == DI_RADIOBUTTON)
        return CurItem->Selected;
      return 0;

    case DM_SET3STATE:
      if(Type == DI_CHECKBOX)
      {
        int OldState=CurItem->Flags&DIF_3STATE?TRUE:FALSE;
        if(Param2)
          CurItem->Flags|=DIF_3STATE;
        else
          CurItem->Flags&=~DIF_3STATE;
        return OldState;
      }
      return 0;

    case DM_SETCHECK:
      if(Type == DI_CHECKBOX || Type == DI_RADIOBUTTON)
      {
        int Selected=CurItem->Selected;
        if(Type == DI_CHECKBOX && (CurItem->Flags&DIF_3STATE))
          Param2%=3;
        else
          Param2&=1;
        CurItem->Selected=Param2;
        if(CurItem->Selected != (unsigned int)Param2 && Dlg->DialogMode.Check(DMODE_SHOW))
        {
          Dlg->ShowDialog(Param1);
          ScrBuf.Flush();
        }
        return Selected;
      }
      return 0;

    case DN_DRAWDLGITEM:
      // ����������� ������ ���!
      Dialog::ConvertItem(CVTITEM_TOPLUGIN,&PluginDialogItem,CurItem,1);
      I=Dlg->DlgProc(hDlg,Msg,Param1,(long)&PluginDialogItem);
      Dialog::ConvertItem(CVTITEM_FROMPLUGIN,&PluginDialogItem,CurItem,1);
      return I;

    case DM_SETREDRAW:
      if(Dlg->DialogMode.Check(DMODE_INITOBJECTS))
        Dlg->Show();
      return 0;

    /* $ 08.09.2000 SVS
      - ���� �������, �� DM_SETFOCUS ����� ��� � ������� :-)
    */
    case DM_SETFOCUS:
//      if(!Dialog::IsFocused(Dlg->Item[Param1].Type))
//        return FALSE;
      if(Dlg->FocusPos == Param1) // ��� � ��� ����������� ���!
        return TRUE;
      if(Dlg->ChangeFocus2(Dlg->FocusPos,Param1) == Param1)
      {
        Dlg->ShowDialog();
        return TRUE;
      }
      return FALSE;
    /* SVS $ */

    /* $ 20.10.2000 SVS
      �������� ID ������
    */
    case DM_GETFOCUS:
      return Dlg->FocusPos;
    /* SVS $ */

    case DM_GETTEXTPTR:
      if(Param2)
      {
        struct FarDialogItemData IData;
        IData.PtrData=(char *)Param2;
        IData.PtrLength=0;
        return Dialog::SendDlgMessage(hDlg,DM_GETTEXT,Param1,(long)&IData);
      }

    case DM_GETTEXT:
      if(Param2) // ���� ����� NULL, �� ��� ��� ���� ������ �������� ������
      {
        struct FarDialogItemData *did=(struct FarDialogItemData*)Param2;
        Len=0;
        switch(Type)
        {
          case DI_COMBOBOX:
          case DI_EDIT:
          case DI_PSWEDIT:
          case DI_FIXEDIT:
            if(!CurItem->ObjPtr)
              break;
            ((Edit *)(CurItem->ObjPtr))->GetString(Str,sizeof(Str));
            Ptr=Str;

          case DI_TEXT:
          case DI_VTEXT:
          case DI_SINGLEBOX:
          case DI_DOUBLEBOX:
          case DI_CHECKBOX:
          case DI_RADIOBUTTON:
          case DI_BUTTON:

            Len=strlen(Ptr)+1;
            if (!(CurItem->Flags & DIF_NOBRACKETS) && Type == DI_BUTTON)
            {
              Ptr+=2;
              Len-=4;
            }

            if(!did->PtrLength)
              did->PtrLength=Len;
            else if(Len > did->PtrLength)
              Len=did->PtrLength;

            if(Len > 0 && did->PtrData)
            {
              memmove(did->PtrData,Ptr,Len);
              did->PtrData[Len]=0;
            }
            break;

          case DI_USERCONTROL:
            did->PtrLength=CurItem->Ptr.PtrLength;
            did->PtrData=(char*)CurItem->Ptr.PtrData;
            break;

          case DI_LISTBOX:
          {
//            if(!CurItem->ListPtr)
//              break;
//            did->PtrLength=CurItem->ListPtr->GetUserData(did->PtrData,did->PtrLength,-1);
            break;
          }

          default:  // �������������, ��� ��������
            did->PtrLength=0;
            break;
        }
        return Len-(!Len?0:1);
      }
      // ����� ��������� �� ������ return, �.�. ����� �������� ������
      // ������������� ����� ������ ���� "case DM_GETTEXTLENGTH"!!!

    case DM_GETTEXTLENGTH:
      switch(Type)
      {
        case DI_BUTTON:
          Len=strlen(Ptr)+1;
          if (!(CurItem->Flags & DIF_NOBRACKETS))
            Len-=4;
          break;

        case DI_USERCONTROL:
          Len=CurItem->Ptr.PtrLength;
          break;

        case DI_TEXT:
        case DI_VTEXT:
        case DI_SINGLEBOX:
        case DI_DOUBLEBOX:
        case DI_CHECKBOX:
        case DI_RADIOBUTTON:
          Len=strlen(Ptr)+1;
          break;

        case DI_COMBOBOX:
        case DI_EDIT:
        case DI_PSWEDIT:
        case DI_FIXEDIT:
          if(CurItem->ObjPtr)
          {
            Len=((Edit *)(CurItem->ObjPtr))->GetLength()+1;
            break;
          }

        case DI_LISTBOX:
        {
          Len=0;
          struct MenuItem *ListMenuItem;
          if((ListMenuItem=CurItem->ListPtr->GetItemPtr(-1)) != NULL)
          {
            Len=strlen(ListMenuItem->Name)+1;
          }
          break;
        }

        default:
          Len=0;
          break;
      }
      return Len-(!Len?0:1);;

    case DM_SETTEXTPTR:
    {
      if(!Param2)
        return 0;

      struct FarDialogItemData IData;
      IData.PtrData=(char *)Param2;
      IData.PtrLength=strlen(IData.PtrData);
      return Dialog::SendDlgMessage(hDlg,DM_SETTEXT,Param1,(long)&IData);
    }


    case DM_SETTEXT:
      if(Param2)
      {
        struct FarDialogItemData *did=(struct FarDialogItemData*)Param2;
        Len=0;
        switch(Type)
        {
          case DI_USERCONTROL:
            CurItem->Ptr.PtrLength=did->PtrLength;
            CurItem->Ptr.PtrData=did->PtrData;
            return CurItem->Ptr.PtrLength;

          case DI_TEXT:
          case DI_VTEXT:
          case DI_SINGLEBOX:
          case DI_DOUBLEBOX:
            if((Len=did->PtrLength) == NULL)
            {
              strncpy(Ptr,(char *)did->PtrData,511);
              Len=strlen(Ptr)+1;
            }
            else
            {
              if((unsigned)did->PtrLength > 511)
                Len=511;
              memmove(Ptr,(char *)did->PtrData,Len);
              Ptr[Len]=0;
            }
            if(Dlg->DialogMode.Check(DMODE_SHOW))
            {
              SetFarTitle(Dlg->GetDialogTitle());
              Dlg->ShowDialog(Param1);
              ScrBuf.Flush();
            }
            return Len-(!Len?0:1);

          case DI_BUTTON:
          case DI_CHECKBOX:
          case DI_RADIOBUTTON:
            if((Len=did->PtrLength) == NULL)
            {
              strncpy(Ptr,(char *)did->PtrData,511);
              Len=strlen(Ptr)+1;
            }
            else
            {
              if((unsigned)did->PtrLength > 511)
                Len=511;
              memmove(Ptr,(char *)did->PtrData,Len);
              Ptr[Len]=0;
            }
            break;

          case DI_COMBOBOX:
          case DI_EDIT:
          case DI_PSWEDIT:
          case DI_FIXEDIT:
            if((Len=did->PtrLength) == NULL)
            {
              strncpy(Ptr,(char *)did->PtrData,511);
              Len=strlen(Ptr)+1;
            }
            else
            {
              if((unsigned)did->PtrLength > 511)
                Len=511;
              memmove(Ptr,(char *)did->PtrData,Len);
              Ptr[Len]=0;
            }
            if(CurItem->ObjPtr)
            {
              ((Edit *)(CurItem->ObjPtr))->SetString((char *)Ptr);
              ((Edit *)(CurItem->ObjPtr))->Select(-1,-1); // ������� ���������
            }
            break;

          case DI_LISTBOX: // ���� �� ������� - �� ����������
            return 0;

          default:  // �������������, ��� ��������
            return 0;
        }
        Dlg->InitDialogObjects(Param1); // ������������������ �������� �������
        if(Dlg->DialogMode.Check(DMODE_SHOW)) // ���������� �� �����????!!!!
        {
          Dlg->ShowDialog(Param1);
          ScrBuf.Flush();
        }
        return strlen((char *)Ptr); //???
      }
      return 0;

    case DM_SETTEXTLENGTH:
      if((Type==DI_EDIT || Type==DI_PSWEDIT ||
          (Type==DI_COMBOBOX && !(CurItem->Flags & DIF_DROPDOWNLIST))) &&
         CurItem->ObjPtr)
      {
        int MaxLen=((Edit *)(CurItem->ObjPtr))->GetMaxLength();

        if((CurItem->Type==DI_EDIT || CurItem->Type==DI_COMBOBOX) &&
           (CurItem->Flags&DIF_VAREDIT))
          CurItem->Ptr.PtrLength=Param2; //???
        else if(Param2 > 511)
          Param2=511;

        ((Edit *)(CurItem->ObjPtr))->SetMaxLength(Param2);

        //if (DialogMode.Check(DMODE_INITOBJECTS)) //???
        Dlg->InitDialogObjects(Param1); // ������������������ �������� �������
        SetFarTitle(Dlg->GetDialogTitle());
        return MaxLen;
      }
      return 0;

    case DM_GETDLGITEM:
      if(Param2 && !IsBadWritePtr((void*)Param2,sizeof(struct FarDialogItem)))
      {
        Dialog::ConvertItem(CVTITEM_TOPLUGIN,(struct FarDialogItem *)Param2,CurItem,1);
/*
        if(IsEdit(Type))
        {
          ((Edit *)(CurItem->ObjPtr))->GetString(Str,sizeof(Str));
          strcpy((char *)Param2,Str);
        }
        else
          strcpy(((struct FarDialogItem *)Param2)->Data,CurItem->Data);
*/
        return TRUE;
      }
      return FALSE;

    case DM_SETDLGITEM:
      if(Param2 && !IsBadReadPtr((void*)Param2,sizeof(struct FarDialogItem)) &&
         Type == ((struct FarDialogItem *)Param2)->Type) // ���� ������ ������ ���
      {
        Dialog::ConvertItem(CVTITEM_FROMPLUGIN,(struct FarDialogItem *)Param2,CurItem,1);
        CurItem->Type=Type;
        // ��� �����, �.�. ������ ����� ���� ��������
        Dlg->InitDialogObjects(Param1);
        SetFarTitle(Dlg->GetDialogTitle());
        if(Dlg->DialogMode.Check(DMODE_SHOW))
        {
          Dlg->ShowDialog(Param1);
          ScrBuf.Flush();
        }
        return TRUE;
      }
      return FALSE;


    /* $ 18.08.2000 SVS
       + ����������/���������� ��������� �������
    */
    case DM_ENABLEREDRAW:
      if(Param1)
        Dlg->IsEnableRedraw++;
      else
        Dlg->IsEnableRedraw--;

      if(!Dlg->IsEnableRedraw)
        if(Dlg->DialogMode.Check(DMODE_INITOBJECTS))
        {
          Dlg->ShowDialog();
          ScrBuf.Flush();
//          Dlg->Show();
        }
      return 0;
    /* SVS $ */

    /* $ 03.01.2001 SVS
        + ��������/������ �������
        Param2: -1 - �������� ���������
                 0 - ��������
                 1 - ��������
        Return:  ���������� ���������
    */
    case DM_SHOWITEM:
    {
      DWORD PrevFlags=CurItem->Flags;
      if(Param2 != -1)
      {
         if(Param2)
           CurItem->Flags&=~DIF_HIDDEN;
         else
           CurItem->Flags|=DIF_HIDDEN;
        if(Dlg->DialogMode.Check(DMODE_SHOW) && !(CurItem->Flags&DIF_HIDDEN))
        {
          // ���� ���,  ����... ������ 1
          Dlg->ShowDialog(Dlg->GetDropDownOpened()?-1:Param1);
          ScrBuf.Flush();
        }
      }
      return (PrevFlags&DIF_HIDDEN)?FALSE:TRUE;
    }

    /* $ 23.08.2000 SVS
       + ��������/�������� ������.
    */
    case DM_SHOWDIALOG:
//      if(!Dlg->IsEnableRedraw)
      {
        if(Param1)
        {
          if(!Dlg->IsVisible())
            Dlg->Show();
        }
        else
        {
          if(Dlg->IsVisible())
            Dlg->Hide();
        }
      }
      return 0;
    /* SVS $ */

    /* $ 23.08.2000 SVS
       + ����������/����� ������ �������.
    */
    case DM_SETDLGDATA:
    {
      long PrewDataDialog=Dlg->DataDialog;
      Dlg->DataDialog=Param2;
      return PrewDataDialog;
    }

    case DM_GETDLGDATA:
    {
      return Dlg->DataDialog;
    }
    /* SVS $ */

    /* $ 23.08.2000 SVS
       + ������� �������(�)
    */
    case DM_KEY:
    {
      int *KeyArray=(int*)Param2;
      Dlg->DialogMode.Set(DMODE_KEY);
      for(I=0; I < Param1; ++I)
        Dlg->ProcessKey(KeyArray[I]);
      Dlg->DialogMode.Skip(DMODE_KEY);
      return 0;
    }
    /* SVS $ */

    /* $ 23.08.2000 SVS
       + ������������� ������� ������
    */
    case DM_CLOSE:
      if(Param1 == -1)
        Dlg->ExitCode=Dlg->FocusPos;
      else
        Dlg->ExitCode=Param1;
      /* $ 17.05.2001 DJ */
      Dlg->CloseDialog();
      /* DJ $ */
      return TRUE;  // �������� � ���������
    /* SVS $ */

    /* $ 25.08.2000 SVS
        + �������� ���������� ����������� ����
    */
    case DM_GETDLGRECT:
    {
      if(Param2 && !IsBadWritePtr((void*)Param2,sizeof(SMALL_RECT)))
      {
        int x1,y1,x2,y2;
        Dlg->GetPosition(x1,y1,x2,y2);
        ((SMALL_RECT*)Param2)->Left=x1;
        ((SMALL_RECT*)Param2)->Top=y1;
        ((SMALL_RECT*)Param2)->Right=x2;
        ((SMALL_RECT*)Param2)->Bottom=y2;
        return TRUE;
      }
      return FALSE;
    }
    /* SVS $ */
    /* $ 23.06.2001 KM */
    case DM_GETDROPDOWNOPENED: // Param1=0; Param2=0
      return Dlg->GetDropDownOpened();
    case DM_SETDROPDOWNOPENED: // Param1=ID; Param2={TRUE|FALSE}
      if (!Param2) // ��������� ����� �������� ��������� ��� �������
      {
        if (Dlg->GetDropDownOpened())
        {
          Dlg->SetDropDownOpened(FALSE);
          Sleep(10);
        }
        return TRUE;
      }
      else if (Param2 && (Type==DI_COMBOBOX || ((Type==DI_EDIT || Type==DI_FIXEDIT ||
               Type==DI_PSWEDIT) && (CurItem->Flags&DIF_HISTORY)))) // ��������� �������� � Param1 ��������� ��� �������
      {
        if (Dlg->GetDropDownOpened())
        {
          Dlg->SetDropDownOpened(FALSE);
          Sleep(10);
        }

        if (Dialog::SendDlgMessage(hDlg,DM_SETFOCUS,Param1,0))
        {
          Dlg->ProcessKey(KEY_CTRLDOWN);
          return TRUE;
        }
        else
          return FALSE;
      }
      return FALSE;
    /* KM $ */
    case DM_SETITEMPOSITION: // Param1 = ID; Param2 = SMALL_RECT
      return Dlg->SetItemRect((int)Param1,(SMALL_RECT*)Param2);

    case DM_RESIZEDIALOG:
      // ������� ����� RESIZE.
      Param1=-1;

    /* $ 30.08.2000 SVS
        + ����������� ����������� �������
    */
    case DM_MOVEDIALOG:
    {
      int W1,H1;

      /* $ 10.08.2001 KM
        - ������� ����������� ������ �������.
      */
      W1=Dlg->X2-Dlg->X1+1;
      H1=Dlg->Y2-Dlg->Y1+1;
      /* KM $ */
      // ���������
      Dlg->OldX1=Dlg->X1;
      Dlg->OldY1=Dlg->Y1;
      Dlg->OldX2=Dlg->X2;
      Dlg->OldY2=Dlg->Y2;
      /* $ 30.05.2001 KM
         - �������� ������������� ������� � ��������� �������
      */
      // �����������
      if(Param1>0)   // ���������?
      {
        Dlg->X1=((COORD*)Param2)->X;
        Dlg->Y1=((COORD*)Param2)->Y;
        /* $ 10.08.2001 KM
          - ������� ����������� ���������� X2 � Y2.
        */
        Dlg->X2=W1-1;
        Dlg->Y2=H1-1;
        /* KM $ */
        Dlg->CheckDialogCoord();
      }
      else if(Param1 == 0)   // ������ ������������
      {
        Dlg->X1+=((COORD*)Param2)->X;
        Dlg->Y1+=((COORD*)Param2)->Y;
      }
      else // Resize, Param2=width/height
      {
        int OldW1,OldH1;
        OldW1=W1;
        OldH1=H1;
        W1=((COORD*)Param2)->X;
        H1=((COORD*)Param2)->Y;
        /* $ 11.10.2001 KM
          - ��� ���� ��������� ��� ����������, � ������ ���������������
            ������ ���� ������� �� ������� ������.
        */
        if(Dlg->X1+W1>ScrX)
          Dlg->X1=ScrX-W1+1;
        if(Dlg->Y1+H1>ScrY)
          Dlg->Y1=ScrY-H1+1;
        /* KM $ */

        if (W1<OldW1 || H1<OldH1)
        {
          Dlg->DialogMode.Set(DMODE_DRAWING);
          DialogItem *Item;
          SMALL_RECT Rect;
          for (I=0;I<Dlg->ItemCount;I++)
          {
            Item=Dlg->Item+I;
            Rect.Left=Item->X1;
            Rect.Top=Item->Y1;
            if (Item->X2>=W1)
            {
              Rect.Right=Item->X2-(OldW1-W1);
              Rect.Bottom=Item->Y2;
              Dlg->SetItemRect(I,&Rect);
            }
            if (Item->Y2>=H1)
            {
              Rect.Right=Item->X2;
              Rect.Bottom=Item->Y2-(OldH1-H1);
              Dlg->SetItemRect(I,&Rect);
            }
          }
          Dlg->DialogMode.Skip(DMODE_DRAWING);
        }
      }
      /* KM $ */
      // ��������� � ���������������
      if(Dlg->X1<0)
        Dlg->X1=0;
      if(Dlg->Y1<0)
        Dlg->Y1=0;
      /* $ 11.10.2001 KM
        - ��� ���� ��������� ��� ����������, � ������ ���������������
          ������ ���� ������� �� ������� ������.
      */
      if(Dlg->X1+W1>ScrX)
        Dlg->X1=ScrX-W1+1;
      if(Dlg->Y1+H1>ScrY)
        Dlg->Y1=ScrY-H1+1;
      /* KM $ */
      /* $ 10.08.2001 KM
        - ������� ����������� ���������� X2 � Y2.
      */
      Dlg->X2=Dlg->X1+W1-1;
      Dlg->Y2=Dlg->Y1+H1-1;
      /* KM $ */

      if(Param1 < 0)   // ������?
      {
        ((COORD*)Param2)->X=Dlg->X2-Dlg->X1+1;
        ((COORD*)Param2)->Y=Dlg->Y2-Dlg->Y1+1;
      }
      else
      {
        ((COORD*)Param2)->X=Dlg->X1;
        ((COORD*)Param2)->Y=Dlg->Y1;
      }

      I=Dlg->IsVisible();// && Dlg->DialogMode.Check(DMODE_INITOBJECTS);
      if(I) Dlg->Hide();
      // �������.
      Dlg->AdjustEditPos(Dlg->X1-Dlg->OldX1,Dlg->Y1-Dlg->OldY1);
      if(I) Dlg->Show(); // ������ ���� ������ ��� �����

      return Param2;
    }
    /* SVS $ */

    /* $ 31.08.2000 SVS
        + ������������/��������� ��������� Enable/Disable ��������
    */
    case DM_ENABLE:
    {
      DWORD PrevFlags=CurItem->Flags;
      if(Param2 != -1)
      {
         if(Param2)
           CurItem->Flags&=~DIF_DISABLE;
         else
           CurItem->Flags|=DIF_DISABLE;
      }
      return (PrevFlags&DIF_DISABLE)?FALSE:TRUE;
    }
    /* SVS $ */

    /* SVS $ */
    case DM_KILLSAVESCREEN:
      {
        if (Dlg->SaveScr) Dlg->SaveScr->Discard();
        if (Dlg->ShadowSaveScr) Dlg->ShadowSaveScr->Discard();
        return TRUE;
      }

    /*
      Msg=DM_ALLKEYMODE
      Param1 = -1 - �������� ���������
             =  0 - ���������
             =  1 - ��������
      Ret = ���������
    */
    case DM_ALLKEYMODE:
    {
      if(Param1 == -1)
        return IsProcessAssignMacroKey;
      BOOL OldIsProcessAssignMacroKey=IsProcessAssignMacroKey;
      IsProcessAssignMacroKey=Param1;
      return OldIsProcessAssignMacroKey;
    }

    // �������� ������� � ������� ��������
    case DM_GETITEMPOSITION: // Param1=ID, Param2=*SMALL_RECT
      if(Param2 && !IsBadWritePtr((void*)Param2,sizeof(SMALL_RECT)))
      {
        RECT Rect;
        if(Dlg->GetItemRect(Param1,Rect))
        {
          ((SMALL_RECT *)Param2)->Left=(short)Rect.left;
          ((SMALL_RECT *)Param2)->Top=(short)Rect.top;
          ((SMALL_RECT *)Param2)->Right=(short)Rect.right;
          ((SMALL_RECT *)Param2)->Bottom=(short)Rect.bottom;
          return TRUE;
        }
      }
      return FALSE;

    case DM_SETMOUSEEVENTNOTIFY: // Param1 = 0 on, 1 off, -1 - get
    {
      int State=Dlg->DialogMode.Check(DMODE_MOUSEEVENT)?TRUE:FALSE;
      if(Param1 != -1)
      {
        if(!Param1)
          Dlg->DialogMode.Skip(DMODE_MOUSEEVENT);
        else
          Dlg->DialogMode.Set(DMODE_MOUSEEVENT);
      }
      return State;
    }

    case DN_RESIZECONSOLE:
      break;
  }

  // ���, ��� ���� �� ������������ - �������� �� ��������� �����������.
  return Dlg->DlgProc(hDlg,Msg,Param1,Param2);
}
/* SVS $ */


//////////////////////////////////////////////////////////////////////////
