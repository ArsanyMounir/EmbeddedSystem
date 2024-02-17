ENTRY(reset)
MEMORY
{
	flash (rx) : o = 0x00000000, l = 512M
	sram (rwx) : o = 0x20000000, l = 512M
}

SECTIONS
{
	.text :
	{
		*(.vectors*)
		*(.text)
		*(.rodata)
		_E_text = . ;
	}> flash
	.data :
	{
		_S_DATA = . ;
		*(.data)
		_E_DATA = . ;
	}>sram AT>flash
	

	.bss :
	{
		_S_bss = . ;
		*(.bss)
		. = ALIGN(4);
		_E_bss = .;
	}> sram
}