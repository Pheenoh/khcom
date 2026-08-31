.syntax unified
	.align 2, 0
	.global func_080D5998
	.thumb
	.thumb_func
	.type func_080D5998, %function
func_080D5998: @ 080D5998
	push {lr}
	ldr r0, _080D59B0 @ =0x02034EC4
	ldr r0, [r0, #0x00]
	movs r1, #0xA0
	lsls r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #0x03
	bl LoadPalette
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D59B0: .4byte 0x02034EC4
.syntax divided
