   .code16
   /* cold boot */
   movw   $0x0472, %di
   movw   %ax, (%di)
   ljmp   $0xFFFF, $0x0000

