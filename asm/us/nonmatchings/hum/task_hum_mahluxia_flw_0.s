.syntax unified
	.align 2, 0
	.global task_hum_mahluxia_flw_0
	.thumb
	.thumb_func
	.type task_hum_mahluxia_flw_0, %function
task_hum_mahluxia_flw_0: @ 08057AF0
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	ldr r0, _08057B70 @ =0x08F6DC84
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x08]
	ldr r0, _08057B74 @ =0x08BCB3D8
	movs r1, #0x80
	lsls r1, r1, #0x01
	bl func_080026A4
	str r0, [r4, #0x04]
	movs r0, #0x00
	str r0, [r4, #0x00]
	ldr r0, [r5, #0x00]
	str r0, [r4, #0x30]
	ldr r0, [r5, #0x04]
	str r0, [r4, #0x34]
	ldr r0, [r5, #0x08]
	str r0, [r4, #0x38]
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08057B78 @ =0x000002CD
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08057B7C @ =0xFFFFFE9A
	adds r0, r0, r1
	str r0, [r4, #0x2C]
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08057B80 @ =0x0000021B
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x66
	negs r0, r0
	str r0, [r4, #0x28]
	adds r4, #0x0C
	ldr r1, _08057B84 @ =0x09EE1CB4
	ldr r2, _08057B88 @ =0x09EE1C94
	adds r0, r4, #0x0
	bl func_08005968
	bl func_080065A4
	movs r1, #0x01
	ands r1, r0
	adds r0, r4, #0x0
	movs r2, #0x01
	bl func_080059A4
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08057B70: .4byte 0x08F6DC84
_08057B74: .4byte 0x08BCB3D8
_08057B78: .4byte 0x000002CD
_08057B7C: .4byte 0xFFFFFE9A
_08057B80: .4byte 0x0000021B
_08057B84: .4byte 0x09EE1CB4
_08057B88: .4byte 0x09EE1C94
.syntax divided
