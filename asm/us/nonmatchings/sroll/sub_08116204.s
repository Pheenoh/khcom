.syntax unified
	.align 2, 0
	.global sub_08116204
	.thumb
	.thumb_func
	.type sub_08116204, %function
sub_08116204:
	adds r3, r0, #0x0
	ldrh r0, [r3, #0x28]
	ldrh r1, [r3, #0x2A]
	cmp r0, r1
	beq _08116224
	ldrh r2, [r3, #0x2A]
	lsls r1, r2, #0x01
	adds r0, r3, #0x0
	adds r0, #0x58
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	adds r2, #0x01
	movs r1, #0xFF
	ands r2, r1
	strh r2, [r3, #0x2A]
	b _08116226
_08116224:
	movs r0, #0x00
_08116226:
	bx lr
.syntax divided
