.syntax unified
	.align 2, 0
	.global task_fld_shadow_0
	.thumb
	.thumb_func
	.type task_fld_shadow_0, %function
task_fld_shadow_0: @ 08036AEC
	push {r4, lr}
	adds r4, r0, #0x0
	str r1, [r4, #0x10]
	ldr r0, [r1, #0x00]
	str r0, [r4, #0x00]
	ldr r0, [r1, #0x04]
	str r0, [r4, #0x04]
	ldr r0, _08036B2C @ =0x08B22BBC
	movs r1, #0x80
	lsls r1, r1, #0x01
	bl func_080026A4
	str r0, [r4, #0x08]
	ldr r0, _08036B30 @ =0x08F69BE4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x0C]
	adds r4, #0x14
	ldr r1, _08036B34 @ =0x09EE1384
	ldr r2, _08036B38 @ =0x09EE1380
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	pop {r4}
	pop {r0}
	bx r0
_08036B2C: .4byte 0x08B22BBC
_08036B30: .4byte 0x08F69BE4
_08036B34: .4byte 0x09EE1384
_08036B38: .4byte 0x09EE1380
.syntax divided
