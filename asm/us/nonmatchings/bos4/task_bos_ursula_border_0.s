.syntax unified
	.align 2, 0
	.global task_bos_ursula_border_0
	.thumb
	.thumb_func
	.type task_bos_ursula_border_0, %function
task_bos_ursula_border_0: @ 080DC8D8
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, _080DC908 @ =0x0979D0B6
	movs r1, #0x80
	lsls r1, r1, #0x04
	bl func_080026A4
	str r0, [r4, #0x00]
	ldr r0, _080DC90C @ =0x0984B0D8
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x04]
	ldrb r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x00
	bl func_0801C298
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080DC908: .4byte 0x0979D0B6
_080DC90C: .4byte 0x0984B0D8
.syntax divided
