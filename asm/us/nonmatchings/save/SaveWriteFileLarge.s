.syntax unified
	.align 2, 0
	.global SaveWriteFileLarge
	.thumb
	.thumb_func
	.type SaveWriteFileLarge, %function
SaveWriteFileLarge: @ 08009298
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0x0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r5, _08009320 @ =0x00000F14
	adds r0, r5, #0x0
	bl func_08000918
	adds r6, r0, #0x0
	adds r1, r5, #0x0
	bl ZeroFill
	adds r0, r6, #0x0
	adds r0, #0x1C
	bl MakeSaveFileLarge
	ldr r0, _08009324 @ =0x09EDB7E8
	ldr r0, [r0, #0x00]
	adds r1, r6, #0x0
	movs r2, #0x18
	bl CopyBytes
	movs r0, #0x00
	strh r0, [r6, #0x18]
	adds r0, r6, #0x0
	adds r1, r5, #0x0
	bl SaveChecksum
	strh r0, [r6, #0x18]
	movs r2, #0x00
	lsls r4, r4, #0x10
	asrs r1, r4, #0x10
	ldr r0, _08009328 @ =0x00001E28
	adds r7, r1, #0x0
	muls r7, r0
	mov r8, r4
_080092E4:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	adds r1, r4, #0x0
	muls r1, r5
	ldr r0, _0800932C @ =0x0E002F20
	adds r1, r1, r0
	adds r1, r7, r1
	adds r0, r6, #0x0
	adds r2, r5, #0x0
	bl WriteAndVerifySramFast
	adds r4, #0x01
	lsls r4, r4, #0x10
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #0x01
	ble _080092E4
	adds r0, r6, #0x0
	bl func_080009C4
	mov r1, r8
	asrs r0, r1, #0x10
	bl SaveWriteHeader
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08009320: .4byte 0x00000F14
_08009324: .4byte 0x09EDB7E8
_08009328: .4byte 0x00001E28
_0800932C: .4byte 0x0E002F20
.syntax divided
