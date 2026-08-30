.syntax unified
	.align 2, 0
	.global func_0800558C
	.thumb
	.thumb_func
	.type func_0800558C, %function
func_0800558C: @ 0800558C
	cmp r0, #0x01
	beq _080055A8
	cmp r0, #0x01
	bcc _080055A0
	cmp r0, #0x02
	beq _080055B0
	cmp r0, #0x03
	beq _080055B8
	movs r0, #0x00
	b _080055C0
_080055A0:
	ldr r0, _080055A4 @ =0x030074FC
	b _080055BA
_080055A4: .4byte 0x030074FC
_080055A8:
	ldr r0, _080055AC @ =0x03007558
	b _080055BA
_080055AC: .4byte 0x03007558
_080055B0:
	ldr r0, _080055B4 @ =0x03007534
	b _080055BA
_080055B4: .4byte 0x03007534
_080055B8:
	ldr r0, _080055C4 @ =0x030074E4
_080055BA:
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_080055C0:
	bx lr
	.byte 0x00, 0x00
_080055C4: .4byte 0x030074E4
.syntax divided
