/* Eng. Mohamed Gamal Saleh Mohamed */

MEMORY
{
	flash(RX) : ORIGIN = 0X00000000, LENGTH = 256K
	sram(RWX) : ORIGIN = 0X20000000, LENGTH = 64K
}

SECTIONS
{
	.text :
	{
		*(.vectors*)
		*(.text*)
		*(.rodata)
		_E_text = .;
	} > flash
	.data :
	{	
		_S_data = .;
		*(.data)
		_E_data = .;
	}> sram AT> flash
	.bss :
	{
		_S_bss = .;
		*(.bss*)
		. = ALIGN(4);
		_E_bss = .;
	} > sram
	 
}