.syntax unified
	.align 2, 0
	.global task_bos_lst_fld_0
	.thumb
	.thumb_func
	.type task_bos_lst_fld_0, %function
task_bos_lst_fld_0: @ 0810FF7C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	ldr r1, [r4, #0x00]
	ldrh r2, [r4, #0x04]
	movs r0, #0x00
	bl LoadBgTiles
	ldr r1, [r4, #0x08]
	ldrh r2, [r4, #0x0C]
	movs r0, #0x00
	bl LoadBgPalette
	ldr r0, _08110030 @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r1, #0x80
	lsls r1, r1, #0x01
	str r1, [r0, #0x24]
	str r1, [r0, #0x28]
	movs r2, #0xF8
	lsls r2, r2, #0x08
	str r2, [r0, #0x08]
	movs r1, #0xF8
	lsls r1, r1, #0x09
	str r1, [r0, #0x0C]
	str r2, [r0, #0x00]
	str r1, [r0, #0x04]
	str r2, [r0, #0x10]
	str r1, [r0, #0x14]
	str r2, [r0, #0x1C]
	str r1, [r0, #0x20]
	movs r2, #0x00
	movs r1, #0x0F
	strh r1, [r0, #0x1A]
	strb r2, [r0, #0x18]
	bl func_0802F1C8
	bl func_0810FE94
	ldr r1, _08110034 @ =0x040000D4
	ldr r0, _08110038 @ =0x09A4D234
	str r0, [r1, #0x00]
	adds r2, r5, #0x0
	adds r2, #0xC4
	str r2, [r1, #0x04]
	ldr r0, _0811003C @ =0x80000340
	str r0, [r1, #0x08]
	ldr r0, [r1, #0x08]
	ldr r0, _08110040 @ =0x09A4F2B4
	str r0, [r1, #0x00]
	ldr r3, _08110044 @ =0x00000744
	adds r0, r5, r3
	str r0, [r1, #0x04]
	ldr r0, _08110048 @ =0x800004A0
	str r0, [r1, #0x08]
	ldr r0, [r1, #0x08]
	movs r1, #0x00
	ldr r7, _0811004C @ =0x0000019F
	ldr r6, _08110050 @ =0x08121400
	movs r4, #0xFF
	ldr r0, _08110054 @ =0x000001FF
	adds r3, r0, #0x0
_0810FFF8:
	adds r0, r1, #0x0
	adds r0, #0x40
	ands r0, r4
	lsls r0, r0, #0x01
	adds r0, r0, r6
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	ands r0, r3
	strh r0, [r2, #0x00]
	adds r2, #0x02
	adds r1, #0x01
	cmp r1, r7
	ble _0810FFF8
	movs r0, #0x00
	str r0, [r5, #0x00]
	str r0, [r5, #0x1C]
	str r0, [r5, #0x04]
	str r0, [r5, #0x08]
	str r0, [r5, #0x0C]
	str r0, [r5, #0x18]
	strh r0, [r5, #0x20]
	strh r0, [r5, #0x22]
	str r0, [r5, #0x10]
	str r0, [r5, #0x14]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08110030: .4byte 0x02039B84
_08110034: .4byte 0x040000D4
_08110038: .4byte 0x09A4D234
_0811003C: .4byte 0x80000340
_08110040: .4byte 0x09A4F2B4
_08110044: .4byte 0x00000744
_08110048: .4byte 0x800004A0
_0811004C: .4byte 0x0000019F
_08110050: .4byte 0x08121400
_08110054: .4byte 0x000001FF
.syntax divided
