ENTRY(_start)

SECTIONS
{
    . = 0x100000; /* Carregado pelo GRUB a partir de 1 MiB */

    _kernel_start = .;

    .multiboot : {
        KEEP(*(.multiboot))
    }

    .text : {
        *(.text*)
    }

    .rodata : {
        *(.rodata*)
    }

    .data : {
        *(.data*)
    }

    .bss : {
        *(.bss*)
        *(COMMON)
    }

    . = ALIGN(0x1000);
    _kernel_end = .;

    /* Espaço reservado para heap ou uso próprio */
    .reserved_ram (NOLOAD) : {
        . = . + 256M; /* 256 MB de RAM reservados */
    }

    _reserved_end = .;
}
