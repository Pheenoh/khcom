.syntax unified
	.align 2, 0
	.global func_080C211C
	.thumb
	.thumb_func
	.type func_080C211C, %function
func_080C211C: @ 080C211C
	push {lr}
	adds r1, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x14
	ldr r0, _080C2138 @ =0x09EF2AA4
	adds r1, r1, r0
	movs r0, #0x01
	movs r2, #0x02
	movs r3, #0x02
	bl func_0800516C
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080C2138: .4byte 0x09EF2AA4
.syntax divided
