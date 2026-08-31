.syntax unified
	.align 2, 0
	.global task_sroll_a_name_0
	.thumb
	.thumb_func
	.type task_sroll_a_name_0, %function
task_sroll_a_name_0: @ 08114758
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	ldrh r0, [r6, #0x00]
	movs r1, #0x00
	strh r0, [r5, #0x02]
	ldr r0, [r6, #0x08]
	str r0, [r5, #0x08]
	ldr r0, [r6, #0x0C]
	str r0, [r5, #0x0C]
	ldr r0, [r6, #0x10]
	str r0, [r5, #0x10]
	ldr r0, [r6, #0x14]
	str r0, [r5, #0x14]
	strh r1, [r5, #0x00]
	strh r1, [r5, #0x04]
	movs r1, #0x00
	ldsh r0, [r6, r1]
	cmp r0, #0x01
	beq _081147B4
	cmp r0, #0x01
	bgt _0811478A
	cmp r0, #0x00
	beq _08114790
	b _08114850
_0811478A:
	cmp r0, #0x02
	beq _081147F0
	b _08114850
_08114790:
	ldr r0, _081147A8 @ =0x09C638BE
	movs r1, #0x8C
	lsls r1, r1, #0x03
	bl LoadObjTiles
	str r0, [r5, #0x18]
	adds r4, r5, #0x0
	adds r4, #0x20
	ldr r1, _081147AC @ =0x09EFB200
	ldr r2, _081147B0 @ =0x09EFB1F8
	b _081147D2
	.byte 0x00, 0x00
_081147A8: .4byte 0x09C638BE
_081147AC: .4byte 0x09EFB200
_081147B0: .4byte 0x09EFB1F8
_081147B4:
	ldr r2, _081147E4 @ =0x09A54218
	ldrh r1, [r6, #0x04]
	lsls r1, r1, #0x03
	adds r0, r1, r2
	ldr r0, [r0, #0x00]
	adds r2, #0x04
	adds r1, r1, r2
	ldrh r1, [r1, #0x00]
	bl LoadObjTiles
	str r0, [r5, #0x18]
	adds r4, r5, #0x0
	adds r4, #0x20
	ldr r1, _081147E8 @ =0x09EFB244
	ldr r2, _081147EC @ =0x09EFB208
_081147D2:
	adds r0, r4, #0x0
	bl AnimInit
	ldrh r1, [r6, #0x02]
	adds r0, r4, #0x0
	movs r2, #0x00
	bl AnimStart
	b _08114850
_081147E4: .4byte 0x09A54218
_081147E8: .4byte 0x09EFB244
_081147EC: .4byte 0x09EFB208
_081147F0:
	ldr r2, _0811481C @ =0x09A54218
	ldrh r1, [r6, #0x04]
	lsls r1, r1, #0x03
	adds r0, r1, r2
	ldr r0, [r0, #0x00]
	adds r2, #0x04
	adds r1, r1, r2
	ldrh r1, [r1, #0x00]
	bl LoadObjTiles
	str r0, [r5, #0x18]
	ldrh r0, [r6, #0x02]
	cmp r0, #0x01
	bne _08114828
	adds r4, r5, #0x0
	adds r4, #0x20
	ldr r1, _08114820 @ =0x09EFB5EC
	ldr r2, _08114824 @ =0x09EFB5B0
	adds r0, r4, #0x0
	bl AnimInit
	b _08114836
_0811481C: .4byte 0x09A54218
_08114820: .4byte 0x09EFB5EC
_08114824: .4byte 0x09EFB5B0
_08114828:
	adds r4, r5, #0x0
	adds r4, #0x20
	ldr r1, _08114860 @ =0x09EFB244
	ldr r2, _08114864 @ =0x09EFB208
	adds r0, r4, #0x0
	bl AnimInit
_08114836:
	adds r0, r4, #0x0
	movs r1, #0x02
	movs r2, #0x00
	bl AnimStart
	ldr r1, _08114868 @ =0x03007554
	movs r2, #0xA0
	lsls r2, r2, #0x01
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r1, _0811486C @ =0x03007564
	movs r0, #0x00
	strh r0, [r1, #0x00]
_08114850:
	ldr r0, _08114870 @ =0x09D6CD74
	movs r1, #0x40
	bl LoadObjPalette
	str r0, [r5, #0x1C]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_08114860: .4byte 0x09EFB244
_08114864: .4byte 0x09EFB208
_08114868: .4byte 0x03007554
_0811486C: .4byte 0x03007564
_08114870: .4byte 0x09D6CD74
.syntax divided
