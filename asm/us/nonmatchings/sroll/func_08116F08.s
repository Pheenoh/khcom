.syntax unified
	.align 2, 0
	.global func_08116F08
	.thumb
	.thumb_func
	.type func_08116F08, %function
func_08116F08: @ 08116F08
	push {lr}
	bl func_08006C24
	bl func_08117170
	bl func_0811FDEC
	bl func_081204E0
	pop {r0}
	bx r0
	.byte 0x00, 0x00, 0x00, 0x48, 0x70, 0x47, 0x20, 0x52, 0x00, 0x00, 0x00, 0x48, 0x70, 0x47, 0x74, 0xB6
	.byte 0xA5, 0x09
.syntax divided
