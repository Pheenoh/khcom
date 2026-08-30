.syntax unified
	.align 2, 0
	.global task_bos_dsd_map_0
	.thumb
	.thumb_func
	.type task_bos_dsd_map_0, %function
task_bos_dsd_map_0: @ 080C3DE4
	push {r4, lr}
	ldr r1, _080C3E54 @ =0x096874E4
	movs r2, #0x80
	lsls r2, r2, #0x08
	movs r0, #0x00
	bl func_080050B8
	ldr r1, _080C3E58 @ =0x096FB744
	movs r2, #0x90
	lsls r2, r2, #0x01
	movs r0, #0x00
	bl func_080050DC
	ldr r1, _080C3E5C @ =0x09EF2E68
	movs r0, #0x00
	movs r2, #0x02
	movs r3, #0x02
	bl func_0800516C
	ldr r4, _080C3E60 @ =0x02039B84
	ldr r0, [r4, #0x00]
	movs r1, #0x80
	lsls r1, r1, #0x01
	str r1, [r0, #0x24]
	str r1, [r0, #0x28]
	movs r2, #0xA0
	lsls r2, r2, #0x08
	str r2, [r0, #0x08]
	movs r1, #0x9B
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
	ldr r0, [r4, #0x00]
	ldr r1, [r0, #0x00]
	lsls r1, r1, #0x08
	lsrs r1, r1, #0x10
	ldr r2, [r0, #0x04]
	lsls r2, r2, #0x08
	lsrs r2, r2, #0x10
	movs r0, #0x00
	bl func_08005244
	pop {r4}
	pop {r0}
	bx r0
_080C3E54: .4byte 0x096874E4
_080C3E58: .4byte 0x096FB744
_080C3E5C: .4byte 0x09EF2E68
_080C3E60: .4byte 0x02039B84
.syntax divided
