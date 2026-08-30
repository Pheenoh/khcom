.syntax unified
	.align 2, 0
	.global func_0805A55C
	.thumb
	.thumb_func
	.type func_0805A55C, %function
func_0805A55C: @ 0805A55C
	movs r2, #0x00
	adds r1, r0, #0x0
_0805A560:
	ldrh r0, [r1, #0x00]
	cmp r0, #0x00
	beq _0805A56C
	adds r1, #0x02
	adds r2, #0x01
	b _0805A560
_0805A56C:
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	bx lr
	.byte 0x00, 0x00
.syntax divided
