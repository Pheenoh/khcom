.syntax unified
	.align 2, 0
	.global func_08009330
	.thumb
	.thumb_func
	.type func_08009330, %function
func_08009330: @ 08009330
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r2, #0x0
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r6, _08009388 @ =0x00000F14
	adds r0, r6, #0x0
	bl func_08000918
	adds r5, r0, #0x0
	adds r1, r6, #0x0
	bl ZeroFill
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	ldr r1, _0800938C @ =0x00001E28
	muls r0, r1
	mov r2, r8
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	muls r1, r6
	ldr r2, _08009390 @ =0x0E002F20
	adds r1, r1, r2
	adds r0, r0, r1
	adds r1, r5, #0x0
	adds r2, r5, #0x0
	adds r3, r6, #0x0
	bl SaveVerifyBlock
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #0x01
	beq _0800939E
	cmp r4, #0x01
	bgt _08009394
	cmp r4, #0x00
	beq _0800939A
	b _080093DA
_08009388: .4byte 0x00000F14
_0800938C: .4byte 0x00001E28
_08009390: .4byte 0x0E002F20
_08009394:
	cmp r4, #0x02
	beq _080093C0
	b _080093DA
_0800939A:
	strb r4, [r5, #0x00]
	b _080093DA
_0800939E:
	ldr r0, _080093BC @ =0x09EDB7E8
	ldr r0, [r0, #0x00]
	adds r1, r5, #0x0
	movs r2, #0x18
	bl CopyBytes
	movs r0, #0x00
	strh r0, [r5, #0x18]
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	bl SaveChecksum
	adds r0, #0x01
	b _080093D8
	.byte 0x00, 0x00
_080093BC: .4byte 0x09EDB7E8
_080093C0:
	ldr r0, _08009408 @ =0x09EDB7E8
	ldr r0, [r0, #0x00]
	adds r1, r5, #0x0
	movs r2, #0x18
	bl CopyBytes
	movs r0, #0x00
	strh r0, [r5, #0x18]
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	bl SaveChecksum
_080093D8:
	strh r0, [r5, #0x18]
_080093DA:
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	ldr r1, _0800940C @ =0x00001E28
	muls r1, r0
	mov r2, r8
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	ldr r2, _08009410 @ =0x00000F14
	muls r0, r2
	ldr r3, _08009414 @ =0x0E002F20
	adds r0, r0, r3
	adds r1, r1, r0
	adds r0, r5, #0x0
	bl WriteAndVerifySramFast
	adds r0, r5, #0x0
	bl func_080009C4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08009408: .4byte 0x09EDB7E8
_0800940C: .4byte 0x00001E28
_08009410: .4byte 0x00000F14
_08009414: .4byte 0x0E002F20
.syntax divided
