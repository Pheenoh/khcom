.syntax unified
	.align 2, 0
	.global mode_jiminy_0
	.thumb
	.thumb_func
	.type mode_jiminy_0, %function
mode_jiminy_0: @ 0805ACE4
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	ldr r5, _0805AE6C @ =0x02034934
	movs r0, #0xD4
	lsls r0, r0, #0x04
	bl func_08000918
	str r0, [r5, #0x00]
	bl func_08004DB0
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x1D
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x01
	movs r1, #0x00
	movs r2, #0x1E
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x02
	movs r1, #0x00
	movs r2, #0x1F
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x03
	movs r1, #0x00
	movs r2, #0x1C
	movs r3, #0x0D
	bl func_08005074
	movs r0, #0x00
	movs r1, #0x00
	bl func_080055C8
	movs r0, #0x01
	movs r1, #0x01
	bl func_080055C8
	movs r0, #0x02
	movs r1, #0x00
	bl func_080055C8
	movs r0, #0x03
	movs r1, #0x00
	bl func_080055C8
	ldr r1, _0805AE70 @ =0x08EE4A64
	movs r2, #0xBA
	lsls r2, r2, #0x06
	movs r0, #0x01
	bl func_080050B8
	ldr r1, _0805AE74 @ =0x08F6DE24
	movs r2, #0x80
	lsls r2, r2, #0x02
	movs r0, #0x01
	bl func_080050DC
	ldr r1, _0805AE78 @ =0x08F61B84
	movs r4, #0x80
	lsls r4, r4, #0x04
	movs r0, #0x01
	adds r2, r4, #0x0
	bl func_0800510C
	ldr r1, _0805AE7C @ =0x08F60B84
	movs r0, #0x02
	adds r2, r4, #0x0
	bl func_0800510C
	ldr r0, _0805AE80 @ =0x08C69C9C
	movs r1, #0x88
	lsls r1, r1, #0x04
	bl func_080026A4
	ldr r1, [r5, #0x00]
	str r0, [r1, #0x04]
	ldr r0, _0805AE84 @ =0x08F6DD64
	movs r1, #0x20
	bl func_08002A14
	ldr r1, [r5, #0x00]
	str r0, [r1, #0x08]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	ldr r0, _0805AE88 @ =0x08C6A88C
	movs r1, #0x40
	bl func_080026A4
	ldr r1, [r5, #0x00]
	str r0, [r1, #0x0C]
	ldr r0, _0805AE8C @ =0x08F6DDE4
	movs r1, #0x20
	bl func_08002A14
	ldr r1, [r5, #0x00]
	str r0, [r1, #0x10]
	ldr r0, _0805AE90 @ =0x08F6DD84
	movs r1, #0x20
	bl func_08002A14
	ldr r1, [r5, #0x00]
	str r0, [r1, #0x14]
	ldr r0, _0805AE94 @ =0x08C6A54E
	movs r1, #0xA0
	lsls r1, r1, #0x01
	bl func_080026A4
	ldr r1, [r5, #0x00]
	str r0, [r1, #0x28]
	ldr r0, _0805AE98 @ =0x08F6DDA4
	movs r1, #0x20
	bl func_08002A14
	ldr r1, [r5, #0x00]
	str r0, [r1, #0x2C]
	ldr r0, _0805AE9C @ =0x08C6A6B8
	movs r1, #0xE0
	lsls r1, r1, #0x01
	bl func_080026A4
	ldr r1, [r5, #0x00]
	str r0, [r1, #0x30]
	ldr r0, _0805AEA0 @ =0x08F6DDC4
	movs r1, #0x20
	bl func_08002A14
	ldr r1, [r5, #0x00]
	str r0, [r1, #0x34]
	ldr r0, _0805AEA4 @ =0xFFFF8000
	str r0, [r1, #0x4C]
	ldr r0, _0805AEA8 @ =0xFFFFF800
	str r0, [r1, #0x50]
	movs r0, #0xA0
	lsls r0, r0, #0x08
	str r0, [r1, #0x54]
	movs r2, #0x00
	str r2, [r1, #0x00]
	adds r0, r1, #0x0
	adds r0, #0x48
	movs r3, #0x00
	strh r2, [r0, #0x00]
	movs r0, #0xC7
	lsls r0, r0, #0x04
	adds r1, r1, r0
	strb r3, [r1, #0x00]
	ldr r0, [r5, #0x00]
	ldr r3, _0805AEAC @ =0x00000C72
	adds r1, r0, r3
	strh r2, [r1, #0x00]
	ldr r1, _0805AEB0 @ =0x00000C74
	adds r0, r0, r1
	strh r2, [r0, #0x00]
	ldr r0, _0805AEB4 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _0805AECC
	movs r0, #0x80
	lsls r0, r0, #0x05
	ldr r1, _0805AEB8 @ =0x0913F0C2
	bl func_080028F8
	ldr r1, [r5, #0x00]
	str r0, [r1, #0x18]
	ldr r0, _0805AEBC @ =0x09614D58
	movs r1, #0x20
	bl func_08002A14
	adds r1, r0, #0x0
	ldr r0, [r5, #0x00]
	str r1, [r0, #0x1C]
	ldr r4, _0805AEC0 @ =0x00000C7C
	adds r0, r0, r4
	ldr r1, _0805AEC4 @ =0x09EED320
	ldr r2, _0805AEC8 @ =0x09EED2BC
	bl func_08005968
	ldr r0, [r5, #0x00]
	adds r0, r0, r4
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	b _0805AF00
	.byte 0x00, 0x00
_0805AE6C: .4byte 0x02034934
_0805AE70: .4byte 0x08EE4A64
_0805AE74: .4byte 0x08F6DE24
_0805AE78: .4byte 0x08F61B84
_0805AE7C: .4byte 0x08F60B84
_0805AE80: .4byte 0x08C69C9C
_0805AE84: .4byte 0x08F6DD64
_0805AE88: .4byte 0x08C6A88C
_0805AE8C: .4byte 0x08F6DDE4
_0805AE90: .4byte 0x08F6DD84
_0805AE94: .4byte 0x08C6A54E
_0805AE98: .4byte 0x08F6DDA4
_0805AE9C: .4byte 0x08C6A6B8
_0805AEA0: .4byte 0x08F6DDC4
_0805AEA4: .4byte 0xFFFF8000
_0805AEA8: .4byte 0xFFFFF800
_0805AEAC: .4byte 0x00000C72
_0805AEB0: .4byte 0x00000C74
_0805AEB4: .4byte 0x02039BB0
_0805AEB8: .4byte 0x0913F0C2
_0805AEBC: .4byte 0x09614D58
_0805AEC0: .4byte 0x00000C7C
_0805AEC4: .4byte 0x09EED320
_0805AEC8: .4byte 0x09EED2BC
_0805AECC:
	movs r0, #0x80
	lsls r0, r0, #0x05
	ldr r1, _0805B030 @ =0x090FDBF4
	bl func_080028F8
	ldr r1, [r5, #0x00]
	str r0, [r1, #0x18]
	ldr r0, _0805B034 @ =0x09614AB8
	movs r1, #0x20
	bl func_08002A14
	adds r1, r0, #0x0
	ldr r0, [r5, #0x00]
	str r1, [r0, #0x1C]
	ldr r4, _0805B038 @ =0x00000C7C
	adds r0, r0, r4
	ldr r1, _0805B03C @ =0x09EECAA0
	ldr r2, _0805B040 @ =0x09EECA44
	bl func_08005968
	ldr r0, [r5, #0x00]
	adds r0, r0, r4
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
_0805AF00:
	bl func_08006314
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _0805AF40
	movs r0, #0x80
	lsls r0, r0, #0x02
	ldr r1, _0805B044 @ =0x08C6A958
	bl func_080028F8
	ldr r4, _0805B048 @ =0x02034934
	ldr r1, [r4, #0x00]
	str r0, [r1, #0x20]
	ldr r0, _0805B04C @ =0x08F6DE04
	movs r1, #0x20
	bl func_08002A14
	adds r1, r0, #0x0
	ldr r0, [r4, #0x00]
	str r1, [r0, #0x24]
	ldr r5, _0805B050 @ =0x00000C94
	adds r0, r0, r5
	ldr r1, _0805B054 @ =0x09EE2678
	ldr r2, _0805B058 @ =0x09EE2668
	bl func_08005968
	ldr r0, [r4, #0x00]
	adds r0, r0, r5
	movs r1, #0x02
	movs r2, #0x01
	bl func_080059A4
_0805AF40:
	movs r0, #0x80
	lsls r0, r0, #0x06
	movs r1, #0x00
	bl func_080028F8
	ldr r4, _0805B048 @ =0x02034934
	ldr r1, [r4, #0x00]
	str r0, [r1, #0x38]
	ldr r0, _0805B05C @ =0x09A3CC9C
	movs r1, #0x20
	bl func_08002A14
	ldr r1, [r4, #0x00]
	str r0, [r1, #0x3C]
	movs r0, #0x80
	lsls r0, r0, #0x04
	movs r1, #0x00
	bl func_080028F8
	ldr r1, [r4, #0x00]
	str r0, [r1, #0x40]
	ldr r0, _0805B060 @ =0x09611AB8
	movs r1, #0x20
	bl func_08002A14
	ldr r1, [r4, #0x00]
	str r0, [r1, #0x44]
	ldr r3, _0805B064 @ =0x00000D3C
	adds r2, r1, r3
	movs r0, #0x00
	strh r0, [r2, #0x00]
	ldr r0, _0805B068 @ =0x00000D38
	adds r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #0x01
	str r0, [r1, #0x00]
	movs r0, #0x00
	movs r1, #0x10
	bl func_08006120
	adds r6, r4, #0x0
	movs r4, #0x60
	movs r5, #0x07
_0805AF96:
	ldr r0, [r6, #0x00]
	adds r0, r0, r4
	movs r1, #0x30
	bl func_08065ACC
	movs r1, #0xC0
	lsls r1, r1, #0x01
	adds r4, r4, r1
	subs r5, #0x01
	cmp r5, #0x00
	bge _0805AF96
	movs r0, #0x00
	bl func_08064B80
	movs r0, #0x80
	lsls r0, r0, #0x02
	movs r1, #0x90
	lsls r1, r1, #0x06
	ldr r2, _0805B06C @ =0x08159FE0
	bl func_08065170
	ldr r2, _0805B048 @ =0x02034934
	ldr r1, [r2, #0x00]
	ldr r3, _0805B070 @ =0x00000C71
	adds r1, r1, r3
	strb r0, [r1, #0x00]
	movs r3, #0x00
	ldr r6, _0805B074 @ =0x00000CD8
	movs r4, #0x00
	ldr r5, _0805B078 @ =0x00000CDA
	adds r7, r2, #0x0
_0805AFD4:
	ldr r0, [r2, #0x00]
	lsls r1, r3, #0x02
	adds r0, r0, r1
	adds r1, r0, r6
	strh r4, [r1, #0x00]
	adds r0, r0, r5
	strh r4, [r0, #0x00]
	adds r3, #0x01
	cmp r3, #0x14
	ble _0805AFD4
	ldr r0, _0805B07C @ =0x02039BB0
	ldr r1, [r0, #0x08]
	movs r0, #0x08
	ands r1, r0
	cmp r1, #0x00
	beq _0805B08C
	ldr r0, [r7, #0x00]
	ldr r1, _0805B080 @ =0x00000D2C
	adds r0, r0, r1
	movs r1, #0x0E
	str r1, [r0, #0x00]
	ldr r0, _0805B084 @ =0x08155554
	movs r2, #0xA8
	lsls r2, r2, #0x01
	adds r0, r0, r2
	movs r3, #0x08
	ldsh r1, [r0, r3]
	ldr r2, [r0, #0x04]
	ldr r3, [r0, #0x10]
	ldr r0, [r0, #0x0C]
	str r0, [sp, #0x000]
	movs r0, #0x80
	str r0, [sp, #0x004]
	movs r0, #0x40
	str r0, [sp, #0x008]
	movs r0, #0x18
	str r0, [sp, #0x00C]
	movs r0, #0x03
	bl func_0805A95C
	ldr r0, [r7, #0x00]
	ldr r1, _0805B088 @ =0x00000CAC
	adds r0, r0, r1
	movs r1, #0x02
	b _0805B0BC
	.byte 0x00, 0x00
_0805B030: .4byte 0x090FDBF4
_0805B034: .4byte 0x09614AB8
_0805B038: .4byte 0x00000C7C
_0805B03C: .4byte 0x09EECAA0
_0805B040: .4byte 0x09EECA44
_0805B044: .4byte 0x08C6A958
_0805B048: .4byte 0x02034934
_0805B04C: .4byte 0x08F6DE04
_0805B050: .4byte 0x00000C94
_0805B054: .4byte 0x09EE2678
_0805B058: .4byte 0x09EE2668
_0805B05C: .4byte 0x09A3CC9C
_0805B060: .4byte 0x09611AB8
_0805B064: .4byte 0x00000D3C
_0805B068: .4byte 0x00000D38
_0805B06C: .4byte 0x08159FE0
_0805B070: .4byte 0x00000C71
_0805B074: .4byte 0x00000CD8
_0805B078: .4byte 0x00000CDA
_0805B07C: .4byte 0x02039BB0
_0805B080: .4byte 0x00000D2C
_0805B084: .4byte 0x08155554
_0805B088: .4byte 0x00000CAC
_0805B08C:
	ldr r0, [r7, #0x00]
	ldr r2, _0805B0C8 @ =0x00000D2C
	adds r0, r0, r2
	str r1, [r0, #0x00]
	ldr r0, _0805B0CC @ =0x08155554
	movs r3, #0x08
	ldsh r1, [r0, r3]
	ldr r2, [r0, #0x04]
	ldr r3, [r0, #0x10]
	ldr r0, [r0, #0x0C]
	str r0, [sp, #0x000]
	movs r0, #0x80
	str r0, [sp, #0x004]
	movs r0, #0x40
	str r0, [sp, #0x008]
	movs r0, #0x18
	str r0, [sp, #0x00C]
	movs r0, #0x03
	bl func_0805A95C
	ldr r0, [r7, #0x00]
	ldr r1, _0805B0D0 @ =0x00000CAC
	adds r0, r0, r1
	movs r1, #0x03
_0805B0BC:
	strh r1, [r0, #0x00]
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0805B0C8: .4byte 0x00000D2C
_0805B0CC: .4byte 0x08155554
_0805B0D0: .4byte 0x00000CAC
.syntax divided
