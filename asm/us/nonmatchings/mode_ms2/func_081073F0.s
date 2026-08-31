.syntax unified
	.align 2, 0
	.global func_081073F0
	.thumb
	.thumb_func
	.type func_081073F0, %function
func_081073F0: @ 081073F0
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	bl func_0810718C
	adds r7, r0, #0x0
	ldr r0, _08107518 @ =0x02035F3C
	mov r9, r0
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0810740E
	bl ReleaseObjPalette
_0810740E:
	ldr r1, _0810751C @ =0x02035F40
	mov r10, r1
	ldr r0, [r1, #0x00]
	cmp r0, #0x00
	beq _0810741C
	bl ReleaseObjTiles
_0810741C:
	ldr r1, _08107520 @ =0x02035F48
	ldr r0, [r1, #0x00]
	cmp r0, #0x00
	beq _08107428
	bl ReleaseObjPalette
_08107428:
	ldr r1, _08107524 @ =0x02035F4C
	ldr r0, [r1, #0x00]
	cmp r0, #0x00
	beq _08107434
	bl ReleaseObjTiles
_08107434:
	ldr r1, _08107528 @ =0x02035E74
	ldr r0, [r1, #0x00]
	cmp r0, #0x00
	beq _08107440
	bl ReleaseObjPalette
_08107440:
	ldrh r0, [r7, #0x00]
	cmp r0, #0x1A
	bls _08107448
	b _08107560
_08107448:
	ldr r0, _0810752C @ =0x02035E2E
	movs r1, #0x00
	ldsh r0, [r0, r1]
	bl func_08107220
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bgt _0810745A
	b _08107560
_0810745A:
	ldrh r2, [r7, #0x02]
	ldr r1, _08107530 @ =0x099937A0
	ldrh r0, [r7, #0x04]
	lsls r0, r0, #0x01
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	mov r8, r0
	ldr r6, _08107534 @ =0x09EE4C80
	lsls r4, r2, #0x02
	adds r4, r4, r2
	lsls r4, r4, #0x03
	adds r0, r6, #0x4
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	adds r5, r4, r6
	ldrh r1, [r5, #0x1A]
	bl LoadObjPalette
	mov r1, r9
	str r0, [r1, #0x00]
	ldr r0, [r5, #0x00]
	ldrh r1, [r5, #0x18]
	bl LoadObjTiles
	mov r1, r10
	str r0, [r1, #0x00]
	ldr r1, _08107538 @ =0x02035F44
	adds r6, #0x08
	adds r4, r4, r6
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r6, _0810753C @ =0x09EE4BF4
	mov r0, r8
	lsls r4, r0, #0x03
	subs r4, r4, r0
	lsls r4, r4, #0x02
	adds r0, r6, #0x4
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	adds r5, r4, r6
	ldrh r1, [r5, #0x16]
	bl LoadObjPalette
	ldr r1, _08107520 @ =0x02035F48
	str r0, [r1, #0x00]
	ldr r0, [r5, #0x00]
	ldrh r1, [r5, #0x14]
	bl LoadObjTiles
	ldr r1, _08107524 @ =0x02035F4C
	str r0, [r1, #0x00]
	ldr r1, _08107540 @ =0x02035F50
	adds r6, #0x08
	adds r4, r4, r6
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r2, _08107544 @ =0x02035F90
	movs r1, #0x00
	ldrh r0, [r7, #0x04]
	cmp r0, #0x03
	bne _081074DA
	movs r1, #0x01
_081074DA:
	strb r1, [r2, #0x00]
	ldrh r0, [r7, #0x04]
	lsls r0, r0, #0x05
	ldr r1, _08107548 @ =0x09A3D2FC
	adds r0, r0, r1
	movs r1, #0x20
	bl LoadObjPalette
	ldr r1, _08107528 @ =0x02035E74
	str r0, [r1, #0x00]
	ldr r4, _0810754C @ =0x02035F98
	ldrh r0, [r7, #0x00]
	bl func_08093C18
	ldr r1, _08107550 @ =0x02035F94
	ldr r1, [r1, #0x00]
	bl func_08065B6C
	strb r0, [r4, #0x00]
	ldr r4, _08107554 @ =0x02035FA0
	ldr r1, _08107558 @ =0x09EE90D0
	ldrh r0, [r7, #0x00]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	ldr r1, _0810755C @ =0x02035F9C
	ldr r1, [r1, #0x00]
	bl func_08065B6C
	strb r0, [r4, #0x00]
	b _0810758A
_08107518: .4byte 0x02035F3C
_0810751C: .4byte 0x02035F40
_08107520: .4byte 0x02035F48
_08107524: .4byte 0x02035F4C
_08107528: .4byte 0x02035E74
_0810752C: .4byte 0x02035E2E
_08107530: .4byte 0x099937A0
_08107534: .4byte 0x09EE4C80
_08107538: .4byte 0x02035F44
_0810753C: .4byte 0x09EE4BF4
_08107540: .4byte 0x02035F50
_08107544: .4byte 0x02035F90
_08107548: .4byte 0x09A3D2FC
_0810754C: .4byte 0x02035F98
_08107550: .4byte 0x02035F94
_08107554: .4byte 0x02035FA0
_08107558: .4byte 0x09EE90D0
_0810755C: .4byte 0x02035F9C
_08107560:
	ldr r0, _08107598 @ =0x02035F3C
	movs r1, #0x00
	str r1, [r0, #0x00]
	ldr r0, _0810759C @ =0x02035F40
	str r1, [r0, #0x00]
	ldr r0, _081075A0 @ =0x02035F44
	str r1, [r0, #0x00]
	ldr r0, _081075A4 @ =0x02035F48
	str r1, [r0, #0x00]
	ldr r0, _081075A8 @ =0x02035F4C
	str r1, [r0, #0x00]
	ldr r0, _081075AC @ =0x02035F50
	str r1, [r0, #0x00]
	ldr r0, _081075B0 @ =0x02035F90
	strb r1, [r0, #0x00]
	ldr r0, _081075B4 @ =0x02035E74
	str r1, [r0, #0x00]
	ldr r0, _081075B8 @ =0x02035F98
	strb r1, [r0, #0x00]
	ldr r0, _081075BC @ =0x02035FA0
	strb r1, [r0, #0x00]
_0810758A:
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08107598: .4byte 0x02035F3C
_0810759C: .4byte 0x02035F40
_081075A0: .4byte 0x02035F44
_081075A4: .4byte 0x02035F48
_081075A8: .4byte 0x02035F4C
_081075AC: .4byte 0x02035F50
_081075B0: .4byte 0x02035F90
_081075B4: .4byte 0x02035E74
_081075B8: .4byte 0x02035F98
_081075BC: .4byte 0x02035FA0
.syntax divided
