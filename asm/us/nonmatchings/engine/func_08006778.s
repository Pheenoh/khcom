.syntax unified
	.align 2, 0
	.global func_08006778
	.thumb
	.thumb_func
	.type func_08006778, %function
func_08006778: @ 08006778
	push {r4, r5, lr}
	adds r5, r0, #0x0
	adds r0, r1, #0x0
	adds r1, r2, #0x0
	ldr r2, _080067A0 @ =0x02034040
	str r5, [r2, #0x00]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl func_080066F4
	ldr r0, _080067A4 @ =0x02034058
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080067AC
	ldr r1, _080067A8 @ =0x0203404C
	ldrh r0, [r5, #0x0E]
	lsls r0, r0, #0x06
	b _080067B2
_080067A0: .4byte 0x02034040
_080067A4: .4byte 0x02034058
_080067A8: .4byte 0x0203404C
_080067AC:
	ldr r1, _08006824 @ =0x0203404C
	ldrh r0, [r5, #0x0E]
	lsls r0, r0, #0x05
_080067B2:
	strh r0, [r1, #0x00]
	ldr r4, _08006828 @ =0x0203404E
	ldrh r1, [r1, #0x00]
	movs r0, #0x80
	lsls r0, r0, #0x08
	bl __divsi3
	strh r0, [r4, #0x00]
	ldr r0, _0800682C @ =0x02034066
	movs r2, #0x01
	negs r2, r2
	adds r1, r2, #0x0
	strh r1, [r0, #0x00]
	ldr r0, _08006830 @ =0x02034068
	strh r1, [r0, #0x00]
	ldr r0, _08006834 @ =0x02034044
	movs r2, #0x00
	strh r2, [r0, #0x00]
	ldr r0, _08006838 @ =0x02034046
	strh r2, [r0, #0x00]
	ldr r0, _0800683C @ =0x02034054
	strb r2, [r0, #0x00]
	ldr r1, _08006840 @ =0x0203406A
	ldrh r0, [r5, #0x16]
	strh r0, [r1, #0x00]
	ldr r0, _08006844 @ =0x02034058
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080067FC
	ldr r0, _08006848 @ =0x0203405C
	movs r1, #0x80
	lsls r1, r1, #0x01
	str r1, [r0, #0x00]
	ldr r0, _0800684C @ =0x02034060
	str r1, [r0, #0x00]
	ldr r0, _08006850 @ =0x02034064
	strb r2, [r0, #0x00]
_080067FC:
	movs r0, #0x00
	bl func_08007E68
	ldr r4, _08006854 @ =0x02034048
	ldr r0, [r4, #0x00]
	ldr r1, [r5, #0x08]
	ldrh r2, [r5, #0x0C]
	bl LoadBgPalette
	bl func_08007E7C
	ldr r0, [r4, #0x00]
	ldr r1, [r5, #0x04]
	ldr r2, _08006858 @ =0x02034056
	ldrh r2, [r2, #0x00]
	bl LoadBgMap
	pop {r4, r5}
	pop {r0}
	bx r0
_08006824: .4byte 0x0203404C
_08006828: .4byte 0x0203404E
_0800682C: .4byte 0x02034066
_08006830: .4byte 0x02034068
_08006834: .4byte 0x02034044
_08006838: .4byte 0x02034046
_0800683C: .4byte 0x02034054
_08006840: .4byte 0x0203406A
_08006844: .4byte 0x02034058
_08006848: .4byte 0x0203405C
_0800684C: .4byte 0x02034060
_08006850: .4byte 0x02034064
_08006854: .4byte 0x02034048
_08006858: .4byte 0x02034056
.syntax divided
