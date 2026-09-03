.syntax unified
	.align 2, 0
	.global mode_worldwarp_0
	.thumb
	.thumb_func
	.type mode_worldwarp_0, %function
mode_worldwarp_0: @ 08100C7C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x010
	ldr r5, _08100D30 @ =0x020354EA
	bl func_080DF750
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, #0x01
	strh r0, [r5, #0x00]
	ldr r4, _08100D34 @ =0x0203550C
	movs r0, #0xA0
	lsls r0, r0, #0x03
	bl EwramAlloc
	str r0, [r4, #0x00]
	bl SpriteReset
	movs r0, #0x00
	movs r1, #0x10
	bl func_08006120
	bl SetBgMode0
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
	movs r1, #0x00
	movs r2, #0x1F
	movs r3, #0x00
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
	ldr r1, _08100D38 @ =0x020354E8
	ldr r2, _08100D3C @ =0x02039BB0
	movs r0, #0x0E
	ldsb r0, [r2, r0]
	strh r0, [r1, #0x00]
	ldr r1, _08100D40 @ =0x0203550A
	movs r3, #0x01
	negs r3, r3
	adds r0, r3, #0x0
	strh r0, [r1, #0x00]
	movs r6, #0x00
	ldr r1, _08100D44 @ =0x020354F0
	movs r4, #0xC3
	lsls r4, r4, #0x01
	ldr r7, _08100D48 @ =0x0000FFFF
_08100D20:
	movs r7, #0x00
	ldsh r0, [r5, r7]
	cmp r6, r0
	bge _08100D4C
	adds r0, r2, r4
	ldrb r0, [r0, #0x00]
	b _08100D50
	.byte 0x00, 0x00
_08100D30: .4byte 0x020354EA
_08100D34: .4byte 0x0203550C
_08100D38: .4byte 0x020354E8
_08100D3C: .4byte 0x02039BB0
_08100D40: .4byte 0x0203550A
_08100D44: .4byte 0x020354F0
_08100D48: .4byte 0x0000FFFF
_08100D4C:
	ldrh r0, [r1, #0x00]
	orrs r0, r3
_08100D50:
	strh r0, [r1, #0x00]
	adds r2, #0x04
	adds r1, #0x02
	adds r6, #0x01
	cmp r6, #0x0C
	ble _08100D20
	ldr r1, _08100E28 @ =0x020357A2
	movs r0, #0x00
	strh r0, [r1, #0x00]
	ldr r1, _08100E2C @ =0x020357A4
	movs r0, #0x10
	strh r0, [r1, #0x00]
	ldr r1, _08100E30 @ =0x020357A8
	ldr r0, _08100E34 @ =0xFFFFF800
	str r0, [r1, #0x00]
	movs r0, #0xA8
	lsls r0, r0, #0x08
	str r0, [r1, #0x04]
	ldr r1, _08100E38 @ =0x020357B0
	ldr r0, _08100E3C @ =0xFFFF8000
	str r0, [r1, #0x00]
	ldr r3, _08100E40 @ =0x020357B4
	ldr r4, _08100E44 @ =0x09EF9384
	ldr r2, _08100E48 @ =0x020354E8
	movs r0, #0x00
	ldsh r1, [r2, r0]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r4
	movs r1, #0x08
	ldsh r0, [r0, r1]
	lsls r0, r0, #0x0B
	movs r6, #0x80
	lsls r6, r6, #0x06
	adds r0, r0, r6
	str r0, [r3, #0x00]
	ldr r3, _08100E4C @ =0x020357B8
	movs r7, #0x00
	ldsh r1, [r2, r7]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r4
	movs r1, #0x0A
	ldsh r0, [r0, r1]
	lsls r0, r0, #0x0B
	ldr r2, _08100E50 @ =0xFFFFFA00
	adds r0, r0, r2
	str r0, [r3, #0x00]
	ldr r1, _08100E54 @ =0x09A3D37C
	movs r2, #0x80
	lsls r2, r2, #0x02
	movs r0, #0x00
	bl LoadBgPalette
	movs r6, #0x00
	ldr r3, _08100E58 @ =0x09EF9488
	mov r8, r3
	movs r7, #0x10
	add r7, r8
	mov r10, r7
	ldr r7, _08100E5C @ =0x020355A8
	movs r5, #0x00
	mov r9, r5
_08100DD2:
	ldr r0, _08100E60 @ =0x020354F0
	lsls r1, r6, #0x01
	adds r4, r1, r0
	movs r1, #0x00
	ldsh r0, [r4, r1]
	cmp r0, #0x00
	ble _08100E6C
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	add r1, r8
	ldr r0, [r1, #0x00]
	ldrh r1, [r1, #0x04]
	bl LoadObjPalette
	str r0, [r7, #0x00]
	movs r3, #0x00
	ldsh r0, [r4, r3]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	mov r0, r8
	adds r0, #0x08
	adds r0, r1, r0
	ldr r0, [r0, #0x00]
	add r1, r8
	ldrh r1, [r1, #0x0C]
	bl LoadObjTiles
	ldr r1, _08100E64 @ =0x02035570
	adds r1, r5, r1
	str r0, [r1, #0x00]
	ldr r2, _08100E68 @ =0x020355E0
	adds r2, r5, r2
	movs r0, #0x00
	ldsh r1, [r4, r0]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	add r0, r10
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x00]
	b _08100E7C
_08100E28: .4byte 0x020357A2
_08100E2C: .4byte 0x020357A4
_08100E30: .4byte 0x020357A8
_08100E34: .4byte 0xFFFFF800
_08100E38: .4byte 0x020357B0
_08100E3C: .4byte 0xFFFF8000
_08100E40: .4byte 0x020357B4
_08100E44: .4byte 0x09EF9384
_08100E48: .4byte 0x020354E8
_08100E4C: .4byte 0x020357B8
_08100E50: .4byte 0xFFFFFA00
_08100E54: .4byte 0x09A3D37C
_08100E58: .4byte 0x09EF9488
_08100E5C: .4byte 0x020355A8
_08100E60: .4byte 0x020354F0
_08100E64: .4byte 0x02035570
_08100E68: .4byte 0x020355E0
_08100E6C:
	mov r1, r9
	str r1, [r7, #0x00]
	ldr r0, _08100FC4 @ =0x02035570
	adds r0, r5, r0
	str r1, [r0, #0x00]
	ldr r0, _08100FC8 @ =0x020355E0
	adds r0, r5, r0
	str r1, [r0, #0x00]
_08100E7C:
	adds r7, #0x04
	adds r5, #0x04
	adds r6, #0x01
	cmp r6, #0x0C
	ble _08100DD2
	ldr r1, _08100FCC @ =0x09A06A7C
	ldr r2, _08100FD0 @ =0x00006BC0
	movs r0, #0x00
	bl LoadBgTiles
	ldr r1, _08100FD4 @ =0x09A35A1C
	movs r2, #0xA0
	lsls r2, r2, #0x03
	movs r0, #0x00
	bl LoadBgMap
	ldr r1, _08100FD8 @ =0x040000D4
	ldr r0, _08100FDC @ =0x09A3641C
	str r0, [r1, #0x00]
	ldr r0, _08100FE0 @ =0x0203550C
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x04]
	ldr r0, _08100FE4 @ =0x80000280
	str r0, [r1, #0x08]
	ldr r0, [r1, #0x08]
	movs r6, #0x00
	ldr r0, _08100FE8 @ =0x09EF9384
	adds r4, r0, #0x0
	adds r4, #0x08
_08100EB6:
	ldr r5, _08100FEC @ =0x020354F0
	lsls r0, r6, #0x01
	adds r0, r0, r5
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r0, #0x00
	blt _08100EE6
	movs r0, #0x00
	str r0, [sp, #0x000]
	ldr r0, _08100FE0 @ =0x0203550C
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x004]
	movs r3, #0x00
	ldsh r0, [r4, r3]
	str r0, [sp, #0x008]
	movs r7, #0x02
	ldsh r0, [r4, r7]
	str r0, [sp, #0x00C]
	movs r0, #0x07
	movs r1, #0x04
	ldr r2, _08100FF0 @ =0x09A3691C
	movs r3, #0x00
	bl func_0810057C
_08100EE6:
	adds r4, #0x14
	adds r6, #0x01
	cmp r6, #0x0C
	ble _08100EB6
	movs r6, #0x00
	ldr r1, _08100FF4 @ =0x020354EA
	movs r2, #0x00
	ldsh r0, [r1, r2]
	subs r0, #0x01
	mov r10, r1
	cmp r6, r0
	bge _08100F6A
	adds r7, r5, #0x0
	ldr r3, _08100FF8 @ =0x099930E8
	mov r9, r3
	ldr r0, _08100FE8 @ =0x09EF9384
	mov r8, r0
_08100F08:
	lsls r0, r6, #0x01
	adds r0, r0, r7
	movs r1, #0x00
	ldsh r0, [r0, r1]
	adds r5, r6, #0x1
	cmp r0, #0x00
	blt _08100F5C
	lsls r0, r5, #0x01
	adds r0, r0, r7
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r0, #0x00
	blt _08100F5C
	lsls r4, r6, #0x02
	adds r4, r4, r6
	lsls r4, r4, #0x02
	add r4, r8
	movs r3, #0x0C
	ldsh r2, [r4, r3]
	lsls r2, r2, #0x03
	add r2, r9
	movs r6, #0x00
	ldsh r0, [r2, r6]
	movs r3, #0x02
	ldsh r1, [r2, r3]
	movs r6, #0x04
	ldsh r3, [r2, r6]
	movs r6, #0x06
	ldsh r2, [r2, r6]
	str r2, [sp, #0x000]
	ldr r2, _08100FE0 @ =0x0203550C
	ldr r2, [r2, #0x00]
	str r2, [sp, #0x004]
	movs r6, #0x0E
	ldsh r2, [r4, r6]
	str r2, [sp, #0x008]
	movs r6, #0x10
	ldsh r2, [r4, r6]
	str r2, [sp, #0x00C]
	ldr r2, _08100FF0 @ =0x09A3691C
	bl func_0810057C
_08100F5C:
	adds r6, r5, #0x0
	ldr r0, _08100FF4 @ =0x020354EA
	movs r1, #0x00
	ldsh r0, [r0, r1]
	subs r0, #0x01
	cmp r6, r0
	blt _08100F08
_08100F6A:
	movs r6, #0x00
	mov r2, r10
	movs r3, #0x00
	ldsh r0, [r2, r3]
	cmp r6, r0
	blt _08100F78
	b _08101082
_08100F78:
	ldr r5, _08100FE0 @ =0x0203550C
	ldr r4, _08100FE8 @ =0x09EF9384
	ldr r7, _08100FFC @ =0xFFF70000
_08100F7E:
	ldr r0, _08100FEC @ =0x020354F0
	lsls r3, r6, #0x01
	adds r0, r3, r0
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r0, #0x00
	blt _0810106C
	ldr r0, _08101000 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	bne _08101010
	cmp r6, #0x08
	bgt _08101004
	adds r3, r3, r6
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	movs r0, #0x09
	str r0, [sp, #0x000]
	ldr r0, [r5, #0x00]
	str r0, [sp, #0x004]
	ldrh r0, [r4, #0x08]
	adds r0, #0x03
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x008]
	ldrh r0, [r4, #0x0A]
	adds r0, #0x02
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	movs r0, #0x03
	b _08101036
	.byte 0x00, 0x00
_08100FC4: .4byte 0x02035570
_08100FC8: .4byte 0x020355E0
_08100FCC: .4byte 0x09A06A7C
_08100FD0: .4byte 0x00006BC0
_08100FD4: .4byte 0x09A35A1C
_08100FD8: .4byte 0x040000D4
_08100FDC: .4byte 0x09A3641C
_08100FE0: .4byte 0x0203550C
_08100FE4: .4byte 0x80000280
_08100FE8: .4byte 0x09EF9384
_08100FEC: .4byte 0x020354F0
_08100FF0: .4byte 0x09A3691C
_08100FF4: .4byte 0x020354EA
_08100FF8: .4byte 0x099930E8
_08100FFC: .4byte 0xFFF70000
_08101000: .4byte 0x02039BB0
_08101004:
	adds r3, r6, #0x0
	subs r3, #0x09
	lsls r3, r3, #0x12
	asrs r3, r3, #0x10
	movs r0, #0x0A
	b _0810101A
_08101010:
	cmp r6, #0x02
	bgt _08101044
	lsls r3, r6, #0x12
	asrs r3, r3, #0x10
	movs r0, #0x15
_0810101A:
	str r0, [sp, #0x000]
	ldr r0, [r5, #0x00]
	str r0, [sp, #0x004]
	ldrh r0, [r4, #0x08]
	adds r0, #0x03
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x008]
	ldrh r0, [r4, #0x0A]
	adds r0, #0x02
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	movs r0, #0x04
_08101036:
	movs r1, #0x01
	ldr r2, _08101040 @ =0x09A3691C
	bl func_0810057C
	b _0810106C
_08101040: .4byte 0x09A3691C
_08101044:
	asrs r3, r7, #0x10
	movs r0, #0x16
	str r0, [sp, #0x000]
	ldr r0, [r5, #0x00]
	str r0, [sp, #0x004]
	ldrh r0, [r4, #0x08]
	adds r0, #0x03
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x008]
	ldrh r0, [r4, #0x0A]
	adds r0, #0x02
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	movs r0, #0x03
	movs r1, #0x01
	ldr r2, _081010B8 @ =0x09A3691C
	bl func_0810057C
_0810106C:
	adds r4, #0x14
	movs r2, #0xC0
	lsls r2, r2, #0x0A
	adds r7, r7, r2
	adds r6, #0x01
	ldr r0, _081010BC @ =0x020354EA
	movs r3, #0x00
	ldsh r0, [r0, r3]
	cmp r6, r0
	bge _08101082
	b _08100F7E
_08101082:
	movs r6, #0x00
	mov r7, r10
	movs r1, #0x00
	ldsh r0, [r7, r1]
	cmp r6, r0
	bge _081010F2
	ldr r5, _081010C0 @ =0x0203550C
	ldr r4, _081010C4 @ =0x09EF9384
_08101092:
	ldr r0, _081010C8 @ =0x020354E8
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r0, r6
	bne _081010CC
	ldr r3, [r5, #0x00]
	movs r7, #0x08
	ldsh r0, [r4, r7]
	str r0, [sp, #0x000]
	movs r1, #0x0A
	ldsh r0, [r4, r1]
	str r0, [sp, #0x004]
	movs r0, #0x03
	movs r1, #0x07
	movs r2, #0x04
	bl func_081004EC
	b _081010E4
	.byte 0x00, 0x00
_081010B8: .4byte 0x09A3691C
_081010BC: .4byte 0x020354EA
_081010C0: .4byte 0x0203550C
_081010C4: .4byte 0x09EF9384
_081010C8: .4byte 0x020354E8
_081010CC:
	ldr r3, [r5, #0x00]
	movs r2, #0x08
	ldsh r0, [r4, r2]
	str r0, [sp, #0x000]
	movs r7, #0x0A
	ldsh r0, [r4, r7]
	str r0, [sp, #0x004]
	movs r0, #0x02
	movs r1, #0x07
	movs r2, #0x04
	bl func_081004EC
_081010E4:
	adds r4, #0x14
	adds r6, #0x01
	ldr r0, _08101144 @ =0x020354EA
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r6, r0
	blt _08101092
_081010F2:
	ldr r0, _08101148 @ =0x0203550C
	ldr r1, [r0, #0x00]
	movs r2, #0xA0
	lsls r2, r2, #0x03
	movs r0, #0x01
	bl LoadBgMap
	ldr r2, _0810114C @ =0x02039BB0
	ldr r0, [r2, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	bne _0810115C
	movs r4, #0x0E
	ldsb r4, [r2, r4]
	ldr r5, _08101150 @ =0x09A0E33C
	movs r0, #0x00
	bl GetBgCharBase
	adds r2, r0, #0x0
	movs r3, #0x90
	lsls r3, r3, #0x01
	adds r2, r2, r3
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl func_08100670
	ldr r0, _08101154 @ =0x020354E8
	movs r6, #0x00
	ldsh r4, [r0, r6]
	ldr r5, _08101158 @ =0x09A0D63C
	movs r0, #0x00
	bl GetBgCharBase
	adds r2, r0, #0x0
	adds r2, #0x20
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl func_08100670
	b _08101192
_08101144: .4byte 0x020354EA
_08101148: .4byte 0x0203550C
_0810114C: .4byte 0x02039BB0
_08101150: .4byte 0x09A0E33C
_08101154: .4byte 0x020354E8
_08101158: .4byte 0x09A0D63C
_0810115C:
	movs r4, #0x0E
	ldsb r4, [r2, r4]
	ldr r5, _0810128C @ =0x09A0FD3C
	movs r0, #0x00
	bl GetBgCharBase
	adds r2, r0, #0x0
	movs r7, #0x90
	lsls r7, r7, #0x01
	adds r2, r2, r7
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl func_08100670
	ldr r0, _08101290 @ =0x020354E8
	movs r1, #0x00
	ldsh r4, [r0, r1]
	ldr r5, _08101294 @ =0x09A0F03C
	movs r0, #0x00
	bl GetBgCharBase
	adds r2, r0, #0x0
	adds r2, #0x20
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl func_08100670
_08101192:
	ldr r0, _08101298 @ =0x09A3D57C
	movs r1, #0x20
	bl LoadObjPalette
	ldr r1, _0810129C @ =0x02035514
	str r0, [r1, #0x00]
	ldr r0, _081012A0 @ =0x0999F488
	movs r1, #0xA0
	lsls r1, r1, #0x03
	bl LoadObjTiles
	ldr r1, _081012A4 @ =0x02035510
	str r0, [r1, #0x00]
	ldr r0, _081012A8 @ =0x09A3D59C
	movs r1, #0x20
	bl LoadObjPalette
	ldr r1, _081012AC @ =0x0203551C
	str r0, [r1, #0x00]
	ldr r0, _081012B0 @ =0x0999FA20
	movs r1, #0xD0
	lsls r1, r1, #0x03
	bl LoadObjTiles
	ldr r1, _081012B4 @ =0x02035518
	str r0, [r1, #0x00]
	ldr r4, _081012B8 @ =0x02035520
	ldr r5, _081012BC @ =0x09EF9898
	ldr r6, _081012C0 @ =0x09EF9870
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	ldr r4, _081012C4 @ =0x02035538
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x01
	movs r2, #0x01
	bl AnimStart
	ldr r0, _081012C8 @ =0x09A3D5BC
	movs r1, #0x20
	bl LoadObjPalette
	ldr r1, _081012CC @ =0x02035554
	str r0, [r1, #0x00]
	ldr r0, _081012D0 @ =0x099A012C
	movs r1, #0xC0
	bl LoadObjTiles
	ldr r1, _081012D4 @ =0x02035550
	str r0, [r1, #0x00]
	ldr r4, _081012D8 @ =0x02035558
	ldr r1, _081012DC @ =0x09EF98B0
	ldr r2, _081012E0 @ =0x09EF98A0
	adds r0, r4, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	ldr r0, _081012E4 @ =0x02035618
	movs r1, #0x18
	bl func_08065ACC
	ldr r0, _081012E8 @ =0x020356E0
	movs r1, #0x18
	bl func_08065ACC
	ldr r4, _081012EC @ =0x020354F0
	ldr r0, _081012F0 @ =0x02039BB0
	ldrb r0, [r0, #0x0E]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x01
	adds r0, r0, r4
	movs r2, #0x00
	ldsh r0, [r0, r2]
	bl func_08100608
	ldr r1, _081012F4 @ =0x020356D8
	strb r0, [r1, #0x00]
	ldr r0, _08101290 @ =0x020354E8
	movs r3, #0x00
	ldsh r0, [r0, r3]
	lsls r0, r0, #0x01
	adds r0, r0, r4
	movs r6, #0x00
	ldsh r0, [r0, r6]
	bl func_0810063C
	ldr r1, _081012F8 @ =0x020357A0
	strb r0, [r1, #0x00]
	movs r0, #0x00
	bl EnableBg
	movs r0, #0x01
	bl EnableBg
	movs r0, #0x02
	bl DisableBg
	movs r0, #0x03
	bl DisableBg
	add sp, #0x010
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0810128C: .4byte 0x09A0FD3C
_08101290: .4byte 0x020354E8
_08101294: .4byte 0x09A0F03C
_08101298: .4byte 0x09A3D57C
_0810129C: .4byte 0x02035514
_081012A0: .4byte 0x0999F488
_081012A4: .4byte 0x02035510
_081012A8: .4byte 0x09A3D59C
_081012AC: .4byte 0x0203551C
_081012B0: .4byte 0x0999FA20
_081012B4: .4byte 0x02035518
_081012B8: .4byte 0x02035520
_081012BC: .4byte 0x09EF9898
_081012C0: .4byte 0x09EF9870
_081012C4: .4byte 0x02035538
_081012C8: .4byte 0x09A3D5BC
_081012CC: .4byte 0x02035554
_081012D0: .4byte 0x099A012C
_081012D4: .4byte 0x02035550
_081012D8: .4byte 0x02035558
_081012DC: .4byte 0x09EF98B0
_081012E0: .4byte 0x09EF98A0
_081012E4: .4byte 0x02035618
_081012E8: .4byte 0x020356E0
_081012EC: .4byte 0x020354F0
_081012F0: .4byte 0x02039BB0
_081012F4: .4byte 0x020356D8
_081012F8: .4byte 0x020357A0
.syntax divided
