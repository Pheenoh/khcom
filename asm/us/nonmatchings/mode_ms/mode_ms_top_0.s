.syntax unified
	.align 2, 0
	.global mode_ms_top_0
	.thumb
	.thumb_func
	.type mode_ms_top_0, %function
mode_ms_top_0: @ 08101C48
	push {r4, r5, lr}
	add sp, #-0x004
	adds r5, r0, #0x0
	bl func_08001F98
	movs r0, #0x00
	movs r1, #0x10
	bl func_08006120
	bl func_08004DB0
	ldr r1, _08101CE8 @ =0x03007554
	movs r2, #0xA1
	lsls r2, r2, #0x01
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r1, _08101CEC @ =0x03007564
	ldr r2, _08101CF0 @ =0x00001010
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x1C
	movs r3, #0x00
	bl SetupBg
	movs r0, #0x01
	movs r1, #0x00
	movs r2, #0x1D
	movs r3, #0x00
	bl SetupBg
	movs r0, #0x02
	movs r1, #0x00
	movs r2, #0x1E
	movs r3, #0x00
	bl SetupBg
	movs r0, #0x03
	movs r1, #0x03
	movs r2, #0x1F
	movs r3, #0x0E
	bl SetupBg
	movs r0, #0x00
	movs r1, #0x03
	bl SetBgPriority
	movs r0, #0x01
	movs r1, #0x02
	bl SetBgPriority
	movs r0, #0x02
	movs r1, #0x01
	bl SetBgPriority
	movs r0, #0x03
	movs r1, #0x00
	bl SetBgPriority
	movs r4, #0x01
	adds r0, r5, #0x0
	ands r0, r4
	cmp r0, #0x00
	beq _08101CCE
	bl func_08102774
_08101CCE:
	movs r2, #0x02
	ands r2, r5
	cmp r2, #0x00
	beq _08101D00
	ldr r1, _08101CF4 @ =0x020358A4
	movs r0, #0x00
	strb r0, [r1, #0x00]
	ldr r1, _08101CF8 @ =0x02035890
	movs r0, #0x07
	strh r0, [r1, #0x00]
	ldr r2, _08101CFC @ =0x020357C0
	b _08101D26
	.byte 0x00, 0x00
_08101CE8: .4byte 0x03007554
_08101CEC: .4byte 0x03007564
_08101CF0: .4byte 0x00001010
_08101CF4: .4byte 0x020358A4
_08101CF8: .4byte 0x02035890
_08101CFC: .4byte 0x020357C0
_08101D00:
	ldr r0, _08101D50 @ =0x020358A4
	strb r4, [r0, #0x00]
	ldr r0, _08101D54 @ =0x02035890
	strh r2, [r0, #0x00]
	ldr r1, _08101D58 @ =0x02035892
	movs r0, #0x10
	strh r0, [r1, #0x00]
	ldr r1, _08101D5C @ =0x02035898
	ldr r0, _08101D60 @ =0xFFFFF800
	str r0, [r1, #0x00]
	movs r0, #0xA8
	lsls r0, r0, #0x08
	str r0, [r1, #0x04]
	ldr r1, _08101D64 @ =0x020358A0
	ldr r0, _08101D68 @ =0xFFFF8000
	str r0, [r1, #0x00]
	ldr r0, _08101D6C @ =0x020357C0
	strh r2, [r0, #0x00]
	adds r2, r0, #0x0
_08101D26:
	ldr r0, _08101D70 @ =0x02035878
	movs r1, #0x00
	strh r1, [r0, #0x00]
	ldr r0, _08101D74 @ =0x0203587A
	strh r1, [r0, #0x00]
	ldr r0, _08101D78 @ =0x0203587C
	strh r1, [r0, #0x00]
	movs r0, #0x00
	ldsh r1, [r2, r0]
	cmp r1, #0x00
	bne _08101D8C
	ldr r0, _08101D7C @ =0x02035880
	str r1, [r0, #0x00]
	ldr r0, _08101D80 @ =0x02035884
	str r1, [r0, #0x00]
	ldr r0, _08101D84 @ =0x02035888
	str r1, [r0, #0x00]
	ldr r0, _08101D88 @ =0x0203588C
	str r1, [r0, #0x00]
	b _08101DA8
	.byte 0x00, 0x00
_08101D50: .4byte 0x020358A4
_08101D54: .4byte 0x02035890
_08101D58: .4byte 0x02035892
_08101D5C: .4byte 0x02035898
_08101D60: .4byte 0xFFFFF800
_08101D64: .4byte 0x020358A0
_08101D68: .4byte 0xFFFF8000
_08101D6C: .4byte 0x020357C0
_08101D70: .4byte 0x02035878
_08101D74: .4byte 0x0203587A
_08101D78: .4byte 0x0203587C
_08101D7C: .4byte 0x02035880
_08101D80: .4byte 0x02035884
_08101D84: .4byte 0x02035888
_08101D88: .4byte 0x0203588C
_08101D8C:
	ldr r1, _08101E1C @ =0x02035880
	ldr r0, _08101E20 @ =0xFFFF9F00
	str r0, [r1, #0x00]
	ldr r1, _08101E24 @ =0x02035884
	movs r0, #0x84
	lsls r0, r0, #0x06
	str r0, [r1, #0x00]
	ldr r1, _08101E28 @ =0x02035888
	ldr r0, _08101E2C @ =0xFFFFE400
	str r0, [r1, #0x00]
	ldr r1, _08101E30 @ =0x0203588C
	movs r0, #0xBC
	lsls r0, r0, #0x08
	str r0, [r1, #0x00]
_08101DA8:
	ldr r0, _08101E34 @ =0x020358BC
	movs r2, #0x01
	negs r2, r2
	adds r1, r2, #0x0
	strh r1, [r0, #0x00]
	ldr r0, _08101E38 @ =0x020358BE
	strh r1, [r0, #0x00]
	ldr r1, _08101E3C @ =0x020358C0
	movs r0, #0x00
	strb r0, [r1, #0x00]
	ldr r1, _08101E40 @ =0x09A3D79C
	movs r0, #0x00
	movs r2, #0x60
	bl LoadBgPalette
	ldr r1, _08101E44 @ =0x09A10A3C
	movs r2, #0xCD
	lsls r2, r2, #0x05
	movs r0, #0x00
	bl LoadBgTiles
	bl func_08101518
	adds r4, r0, #0x0
	movs r0, #0x00
	bl GetBgCharBase
	adds r2, r0, #0x0
	adds r2, #0x20
	ldr r1, _08101E48 @ =0x09A123DC
	movs r0, #0x05
	str r0, [sp, #0x000]
	adds r0, r4, #0x0
	movs r3, #0x20
	bl func_08101588
	ldr r1, _08101E4C @ =0x09A36EDC
	movs r4, #0xA0
	lsls r4, r4, #0x03
	movs r0, #0x00
	adds r2, r4, #0x0
	bl LoadBgMap
	ldr r1, _08101E50 @ =0x09A373DC
	movs r0, #0x01
	adds r2, r4, #0x0
	bl LoadBgMap
	ldr r0, _08101E54 @ =0x020358A4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08101E5C
	ldr r1, _08101E58 @ =0x09A378DC
	movs r0, #0x02
	adds r2, r4, #0x0
	bl LoadBgMap
	b _08101E66
_08101E1C: .4byte 0x02035880
_08101E20: .4byte 0xFFFF9F00
_08101E24: .4byte 0x02035884
_08101E28: .4byte 0x02035888
_08101E2C: .4byte 0xFFFFE400
_08101E30: .4byte 0x0203588C
_08101E34: .4byte 0x020358BC
_08101E38: .4byte 0x020358BE
_08101E3C: .4byte 0x020358C0
_08101E40: .4byte 0x09A3D79C
_08101E44: .4byte 0x09A10A3C
_08101E48: .4byte 0x09A123DC
_08101E4C: .4byte 0x09A36EDC
_08101E50: .4byte 0x09A373DC
_08101E54: .4byte 0x020358A4
_08101E58: .4byte 0x09A378DC
_08101E5C:
	ldr r1, _08101F6C @ =0x09A37DDC
	movs r0, #0x02
	adds r2, r4, #0x0
	bl LoadBgMap
_08101E66:
	ldr r0, _08101F70 @ =0x09A3D7FC
	movs r2, #0x00
	ldr r4, _08101F74 @ =0x02035818
	ldr r3, _08101F78 @ =0x02035820
	movs r1, #0x01
_08101E70:
	stm r3!, {r2}
	stm r4!, {r2}
	subs r1, #0x01
	cmp r1, #0x00
	bge _08101E70
	movs r1, #0x20
	bl LoadObjPalette
	ldr r1, _08101F7C @ =0x020357CC
	str r0, [r1, #0x00]
	ldr r0, _08101F80 @ =0x099A2B62
	movs r1, #0x80
	lsls r1, r1, #0x03
	bl LoadObjTiles
	ldr r1, _08101F84 @ =0x020357C8
	str r0, [r1, #0x00]
	ldr r0, _08101F88 @ =0x09A3D85C
	movs r1, #0x20
	bl LoadObjPalette
	ldr r1, _08101F8C @ =0x020357D4
	str r0, [r1, #0x00]
	ldr r0, _08101F90 @ =0x099A36F8
	movs r1, #0xA0
	lsls r1, r1, #0x03
	bl LoadObjTiles
	ldr r1, _08101F94 @ =0x020357D0
	str r0, [r1, #0x00]
	ldr r0, _08101F98 @ =0x020357D8
	ldr r1, _08101F9C @ =0x09EF99D0
	ldr r2, _08101FA0 @ =0x09EF99A8
	bl AnimInit
	ldr r0, _08101FA4 @ =0x08F683A4
	movs r1, #0x20
	bl LoadObjPalette
	ldr r1, _08101FA8 @ =0x020357F4
	str r0, [r1, #0x00]
	ldr r0, _08101FAC @ =0x088C56C6
	movs r1, #0xC0
	lsls r1, r1, #0x02
	bl LoadObjTiles
	ldr r1, _08101FB0 @ =0x020357F0
	str r0, [r1, #0x00]
	ldr r4, _08101FB4 @ =0x020357F8
	ldr r1, _08101FB8 @ =0x09EDEA6C
	ldr r2, _08101FBC @ =0x09EDEA68
	adds r0, r4, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	ldr r0, _08101FC0 @ =0x08F69BA4
	movs r1, #0x20
	bl LoadObjPalette
	ldr r1, _08101FC4 @ =0x02035814
	str r0, [r1, #0x00]
	ldr r0, _08101FC8 @ =0x08B22BBC
	movs r1, #0x80
	lsls r1, r1, #0x01
	bl LoadObjTiles
	ldr r1, _08101FCC @ =0x02035810
	str r0, [r1, #0x00]
	ldr r0, _08101FD0 @ =0x09617D58
	movs r1, #0x20
	bl LoadObjPalette
	ldr r1, _08101FD4 @ =0x0203585C
	str r0, [r1, #0x00]
	ldr r0, _08101FD8 @ =0x092028EC
	movs r1, #0xC0
	lsls r1, r1, #0x04
	bl LoadObjTiles
	ldr r1, _08101FDC @ =0x02035858
	str r0, [r1, #0x00]
	ldr r4, _08101FE0 @ =0x02035860
	ldr r1, _08101FE4 @ =0x09EEEAC8
	ldr r2, _08101FE8 @ =0x09EEEA98
	adds r0, r4, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	ldr r0, _08101FEC @ =0x020357C0
	movs r1, #0x00
	ldsh r0, [r0, r1]
	bl func_08101740
	bl func_08101654
	bl func_081015E8
	ldr r0, _08101FF0 @ =0x020358A8
	movs r1, #0x01
	bl TaskPoolInit
	movs r0, #0x00
	bl func_08004FC8
	movs r0, #0x01
	bl func_08004FC8
	movs r0, #0x02
	bl func_08004FC8
	movs r0, #0x03
	bl func_0800501C
	add sp, #0x004
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08101F6C: .4byte 0x09A37DDC
_08101F70: .4byte 0x09A3D7FC
_08101F74: .4byte 0x02035818
_08101F78: .4byte 0x02035820
_08101F7C: .4byte 0x020357CC
_08101F80: .4byte 0x099A2B62
_08101F84: .4byte 0x020357C8
_08101F88: .4byte 0x09A3D85C
_08101F8C: .4byte 0x020357D4
_08101F90: .4byte 0x099A36F8
_08101F94: .4byte 0x020357D0
_08101F98: .4byte 0x020357D8
_08101F9C: .4byte 0x09EF99D0
_08101FA0: .4byte 0x09EF99A8
_08101FA4: .4byte 0x08F683A4
_08101FA8: .4byte 0x020357F4
_08101FAC: .4byte 0x088C56C6
_08101FB0: .4byte 0x020357F0
_08101FB4: .4byte 0x020357F8
_08101FB8: .4byte 0x09EDEA6C
_08101FBC: .4byte 0x09EDEA68
_08101FC0: .4byte 0x08F69BA4
_08101FC4: .4byte 0x02035814
_08101FC8: .4byte 0x08B22BBC
_08101FCC: .4byte 0x02035810
_08101FD0: .4byte 0x09617D58
_08101FD4: .4byte 0x0203585C
_08101FD8: .4byte 0x092028EC
_08101FDC: .4byte 0x02035858
_08101FE0: .4byte 0x02035860
_08101FE4: .4byte 0x09EEEAC8
_08101FE8: .4byte 0x09EEEA98
_08101FEC: .4byte 0x020357C0
_08101FF0: .4byte 0x020358A8
.syntax divided
