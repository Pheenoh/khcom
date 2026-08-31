.syntax unified
	.align 2, 0
	.global task_sroll_c_char_0
	.thumb
	.thumb_func
	.type task_sroll_c_char_0, %function
task_sroll_c_char_0: @ 08115180
	push {r4, r5, lr}
	adds r4, r0, #0x0
	cmp r1, #0x00
	bne _081151D4
	ldr r0, _081151C4 @ =0x09C8D47A
	movs r1, #0x9A
	lsls r1, r1, #0x05
	bl LoadObjTiles
	str r0, [r4, #0x18]
	ldr r0, _081151C8 @ =0x09D6CF54
	movs r1, #0xE0
	bl LoadObjPalette
	str r0, [r4, #0x1C]
	movs r5, #0x00
	adds r4, #0x20
_081151A2:
	adds r0, r4, #0x0
	ldr r1, _081151CC @ =0x09EFB9B8
	ldr r2, _081151D0 @ =0x09EFB840
	bl AnimInit
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0x0
	movs r2, #0x00
	bl AnimStart
	adds r4, #0x18
	adds r5, #0x01
	cmp r5, #0x04
	ble _081151A2
	b _0811520C
	.byte 0x00, 0x00
_081151C4: .4byte 0x09C8D47A
_081151C8: .4byte 0x09D6CF54
_081151CC: .4byte 0x09EFB9B8
_081151D0: .4byte 0x09EFB840
_081151D4:
	ldr r0, _08115214 @ =0x09C8F1FA
	movs r1, #0x92
	lsls r1, r1, #0x05
	bl LoadObjTiles
	str r0, [r4, #0x18]
	ldr r0, _08115218 @ =0x09D6D034
	movs r1, #0xE0
	bl LoadObjPalette
	str r0, [r4, #0x1C]
	movs r5, #0x00
	adds r4, #0x20
_081151EE:
	adds r0, r4, #0x0
	ldr r1, _0811521C @ =0x09EFBAD4
	ldr r2, _08115220 @ =0x09EFB9CC
	bl AnimInit
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0x0
	movs r2, #0x00
	bl AnimStart
	adds r4, #0x18
	adds r5, #0x01
	cmp r5, #0x04
	ble _081151EE
_0811520C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08115214: .4byte 0x09C8F1FA
_08115218: .4byte 0x09D6D034
_0811521C: .4byte 0x09EFBAD4
_08115220: .4byte 0x09EFB9CC
.syntax divided
