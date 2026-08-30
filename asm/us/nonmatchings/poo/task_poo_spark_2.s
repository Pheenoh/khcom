.syntax unified
	.align 2, 0
	.global task_poo_spark_2
	.thumb
	.thumb_func
	.type task_poo_spark_2, %function
task_poo_spark_2: @ 080D0994
	push {r4, r5, r6, lr}
	add sp, #-0x010
	adds r6, r0, #0x0
	ldr r5, [r6, #0x00]
	asrs r5, r5, #0x08
	ldr r0, _080D09F4 @ =0x0203C40C
	ldrh r0, [r0, #0x00]
	subs r5, r5, r0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r4, [r6, #0x04]
	asrs r4, r4, #0x08
	ldr r0, [r6, #0x08]
	asrs r0, r0, #0x08
	adds r4, r4, r0
	ldr r0, _080D09F8 @ =0x0203C3F8
	ldrh r0, [r0, #0x00]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r6, #0x0
	adds r0, #0x10
	bl func_08005AFC
	adds r2, r0, #0x0
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r3, [r6, #0x28]
	ldr r0, [r6, #0x2C]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	movs r0, #0x80
	lsls r0, r0, #0x03
	str r0, [sp, #0x008]
	movs r0, #0x50
	str r0, [sp, #0x00C]
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080023E0
	add sp, #0x010
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D09F4: .4byte 0x0203C40C
_080D09F8: .4byte 0x0203C3F8
.syntax divided
