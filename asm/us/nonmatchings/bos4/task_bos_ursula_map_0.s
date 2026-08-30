.syntax unified
	.align 2, 0
	.global task_bos_ursula_map_0
	.thumb
	.thumb_func
	.type task_bos_ursula_map_0, %function
task_bos_ursula_map_0: @ 080DC640
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x1A
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x01
	movs r1, #0x00
	movs r2, #0x18
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x01
	movs r1, #0x03
	bl func_080055C8
	movs r0, #0x00
	movs r1, #0x02
	bl func_080055C8
	ldr r1, [r4, #0x00]
	ldrh r2, [r4, #0x04]
	movs r0, #0x01
	bl func_080050B8
	ldr r1, [r4, #0x08]
	ldrh r2, [r4, #0x0C]
	movs r0, #0x01
	bl func_080050DC
	adds r4, #0x10
	movs r0, #0x01
	adds r1, r4, #0x0
	movs r2, #0x02
	movs r3, #0x02
	bl func_0800516C
	ldr r4, _080DC70C @ =0x02039B84
	ldr r0, [r4, #0x00]
	movs r1, #0x80
	lsls r1, r1, #0x01
	str r1, [r0, #0x24]
	str r1, [r0, #0x28]
	movs r2, #0x80
	lsls r2, r2, #0x09
	str r2, [r0, #0x08]
	ldr r1, _080DC710 @ =0x00017100
	str r1, [r0, #0x0C]
	str r2, [r0, #0x00]
	str r1, [r0, #0x04]
	str r2, [r0, #0x10]
	str r1, [r0, #0x14]
	str r2, [r0, #0x1C]
	str r1, [r0, #0x20]
	movs r2, #0x00
	movs r6, #0x00
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
	movs r0, #0x01
	bl func_08005244
	ldr r2, _080DC714 @ =0x03007500
	ldrh r0, [r2, #0x00]
	movs r3, #0x80
	lsls r3, r3, #0x06
	adds r1, r3, #0x0
	orrs r0, r1
	strh r0, [r2, #0x00]
	ldr r1, _080DC718 @ =0x03007530
	movs r0, #0xF0
	strh r0, [r1, #0x00]
	ldr r1, _080DC71C @ =0x03007518
	ldr r2, _080DC720 @ =0x000050A0
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r1, _080DC724 @ =0x03007550
	movs r0, #0x3E
	strh r0, [r1, #0x00]
	ldr r1, _080DC728 @ =0x03007548
	movs r0, #0x3F
	strh r0, [r1, #0x00]
	movs r0, #0xF0
	lsls r0, r0, #0x09
	str r0, [r5, #0x00]
	str r0, [r5, #0x04]
	strh r6, [r5, #0x08]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080DC70C: .4byte 0x02039B84
_080DC710: .4byte 0x00017100
_080DC714: .4byte 0x03007500
_080DC718: .4byte 0x03007530
_080DC71C: .4byte 0x03007518
_080DC720: .4byte 0x000050A0
_080DC724: .4byte 0x03007550
_080DC728: .4byte 0x03007548
.syntax divided
