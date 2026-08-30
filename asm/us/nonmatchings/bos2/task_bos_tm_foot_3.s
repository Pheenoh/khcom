.syntax unified
	.align 2, 0
	.global task_bos_tm_foot_3
	.thumb
	.thumb_func
	.type task_bos_tm_foot_3, %function
task_bos_tm_foot_3: @ 080BB174
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r1, _080BB1B4 @ =0x0000047C
	adds r0, r4, r1
	ldr r0, [r0, #0x00]
	ldrh r1, [r0, #0x28]
	movs r0, #0x08
	ands r0, r1
	cmp r0, #0x00
	bne _080BB19C
	movs r1, #0x93
	lsls r1, r1, #0x02
	adds r0, r4, r1
	bl func_080BA0F8
	movs r1, #0xD9
	lsls r1, r1, #0x02
	adds r0, r4, r1
	bl func_080BA0F8
_080BB19C:
	ldr r0, [r4, #0x08]
	bl func_080028C0
	ldr r0, [r4, #0x14]
	bl func_08002C10
	ldr r0, [r4, #0x18]
	bl func_08002C10
	pop {r4}
	pop {r0}
	bx r0
_080BB1B4: .4byte 0x0000047C
.syntax divided
