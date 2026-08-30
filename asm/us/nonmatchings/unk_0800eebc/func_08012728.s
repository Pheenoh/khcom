.syntax unified
	.align 2, 0
	.global func_08012728
	.thumb
	.thumb_func
	.type func_08012728, %function
func_08012728: @ 08012728
	push {r4, r5, lr}
	add sp, #-0x004
	adds r4, r0, #0x0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r5, sp
	adds r5, #0x02
	mov r0, sp
	adds r1, r5, #0x0
	bl func_08006B80
	bl func_08006BA8
	bl func_08006BA0
	mov r1, sp
	ldrh r2, [r1, #0x00]
	ldrh r1, [r5, #0x00]
	muls r1, r2
	subs r0, r0, r1
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	cmp r0, r4
	bhi _08012784
	ldr r3, _0801278C @ =0x02034928
	ldr r1, [r3, #0x00]
	ldrh r2, [r1, #0x34]
	ldr r0, _08012790 @ =0x0000FFFD
	ands r0, r2
	strh r0, [r1, #0x34]
	adds r1, #0x38
	movs r0, #0x02
	strb r0, [r1, #0x00]
	ldr r3, [r3, #0x00]
	ldrh r1, [r3, #0x34]
	movs r0, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _08012784
	ldr r0, _08012794 @ =0x0000FFF7
	ands r0, r1
	strh r0, [r3, #0x34]
	movs r0, #0x00
	movs r1, #0x08
	bl func_080061E8
_08012784:
	add sp, #0x004
	pop {r4, r5}
	pop {r0}
	bx r0
_0801278C: .4byte 0x02034928
_08012790: .4byte 0x0000FFFD
_08012794: .4byte 0x0000FFF7
.syntax divided
