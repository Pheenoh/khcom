.syntax unified
	.align 2, 0
	.global func_080E08BC
	.thumb
	.thumb_func
	.type func_080E08BC, %function
func_080E08BC: @ 080E08BC
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r1, r1, #0x10
	asrs r3, r1, #0x10
	cmp r3, #0x00
	blt _080E08E0
	ldr r0, _080E08E4 @ =0x02034F2A
	ldrh r0, [r0, #0x00]
	cmp r3, r0
	bge _080E08E0
	lsls r0, r2, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0x00
	blt _080E08E0
	ldr r0, _080E08E8 @ =0x02034F28
	ldrh r1, [r0, #0x00]
	cmp r2, r1
	blt _080E08EC
_080E08E0:
	movs r0, #0x00
	b _080E08F8
_080E08E4: .4byte 0x02034F2A
_080E08E8: .4byte 0x02034F28
_080E08EC:
	ldr r0, _080E08FC @ =0x02034F1C
	muls r1, r3
	adds r1, r1, r2
	lsls r1, r1, #0x05
	ldr r0, [r0, #0x00]
	adds r0, r0, r1
_080E08F8:
	bx lr
	.byte 0x00, 0x00
_080E08FC: .4byte 0x02034F1C
.syntax divided
