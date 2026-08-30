.syntax unified
	.align 2, 0
	.global task_hum_vixen_ice_0
	.thumb
	.thumb_func
	.type task_hum_vixen_ice_0, %function
task_hum_vixen_ice_0: @ 08055674
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	ldr r0, _080556CC @ =0x08F6DCA4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x08]
	ldr r0, _080556D0 @ =0x08EE4264
	movs r1, #0x80
	lsls r1, r1, #0x04
	bl func_080026A4
	str r0, [r4, #0x04]
	str r5, [r4, #0x24]
	movs r0, #0x03
	str r0, [r4, #0x00]
	adds r5, r4, #0x0
	adds r5, #0x0C
	ldr r1, _080556D4 @ =0x09EE26CC
	ldr r2, _080556D8 @ =0x09EE26B4
	adds r0, r5, #0x0
	bl func_08005968
	adds r0, r5, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl func_080059A4
	adds r4, #0x28
	adds r0, r4, #0x0
	movs r1, #0x0C
	movs r2, #0x1B
	movs r3, #0x01
	bl func_080122AC
	adds r0, r4, #0x0
	movs r1, #0x01
	bl func_08012614
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080556CC: .4byte 0x08F6DCA4
_080556D0: .4byte 0x08EE4264
_080556D4: .4byte 0x09EE26CC
_080556D8: .4byte 0x09EE26B4
.syntax divided
