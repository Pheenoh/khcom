.syntax unified
	.align 2, 0
	.global SaveWriteFileSmall
	.thumb
	.thumb_func
	.type SaveWriteFileSmall, %function
SaveWriteFileSmall: @ 0800963C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0x0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r5, #0x83
	lsls r5, r5, #0x03
	adds r0, r5, #0x0
	bl EwramAlloc
	adds r6, r0, #0x0
	adds r1, r5, #0x0
	bl ZeroFill
	adds r0, r6, #0x0
	adds r0, #0x1C
	bl MakeSaveFileSmall
	ldr r0, _080096CC @ =0x09EDB7E8
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
	adds r7, r4, #0x0
	lsls r0, r1, #0x05
	adds r0, r0, r1
	lsls r0, r0, #0x02
	subs r0, r0, r1
	lsls r5, r0, #0x04
_0800968A:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	lsls r1, r4, #0x05
	adds r1, r1, r4
	lsls r1, r1, #0x02
	subs r1, r1, r4
	lsls r1, r1, #0x03
	ldr r0, _080096D0 @ =0x0E001EC0
	adds r1, r1, r0
	adds r1, r5, r1
	adds r0, r6, #0x0
	movs r2, #0x83
	lsls r2, r2, #0x03
	bl WriteAndVerifySramFast
	adds r4, #0x01
	lsls r4, r4, #0x10
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #0x01
	ble _0800968A
	adds r0, r6, #0x0
	bl EwramFree
	movs r1, #0x80
	lsls r1, r1, #0x0A
	adds r0, r7, r1
	asrs r0, r0, #0x10
	bl SaveWriteHeader
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080096CC: .4byte 0x09EDB7E8
_080096D0: .4byte 0x0E001EC0
.syntax divided
