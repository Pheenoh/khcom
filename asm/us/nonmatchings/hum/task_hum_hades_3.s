.syntax unified
	.align 2, 0
	.global task_hum_hades_3
	.thumb
	.thumb_func
	.type task_hum_hades_3, %function
task_hum_hades_3: @ 0804F8B0
	push {r4, lr}
	adds r4, r0, #0x0
	movs r1, #0xEA
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldr r0, [r0, #0x00]
	bl func_080028C0
	movs r1, #0xEC
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldr r0, [r0, #0x00]
	bl func_080028C0
	movs r1, #0xEE
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldr r0, [r0, #0x00]
	bl func_080028C0
	movs r1, #0x8A
	lsls r1, r1, #0x02
	adds r0, r4, r1
	ldr r0, [r0, #0x00]
	bl func_08002C10
	adds r0, r4, #0x0
	bl func_0800E380
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
