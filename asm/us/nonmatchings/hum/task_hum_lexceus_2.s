.syntax unified
	.align 2, 0
	.global task_hum_lexceus_2
	.thumb
	.thumb_func
	.type task_hum_lexceus_2, %function
task_hum_lexceus_2: @ 08056E74
	push {r4, r5, lr}
	adds r4, r0, #0x0
	bl func_0800EFE8
	movs r0, #0xE6
	lsls r0, r0, #0x01
	adds r5, r4, r0
	movs r1, #0x00
	ldsh r0, [r5, r1]
	cmp r0, #0x00
	ble _08056EB6
	movs r2, #0xB4
	lsls r2, r2, #0x01
	adds r0, r4, r2
	adds r2, #0x68
	adds r1, r4, r2
	ldr r1, [r1, #0x00]
	ldrh r2, [r5, #0x00]
	bl func_080058FC
	movs r1, #0xB6
	lsls r1, r1, #0x01
	adds r0, r4, r1
	movs r2, #0xEA
	lsls r2, r2, #0x01
	adds r1, r4, r2
	ldr r1, [r1, #0x00]
	ldrh r2, [r5, #0x00]
	bl func_080058FC
	ldrh r0, [r5, #0x00]
	subs r0, #0x01
	strh r0, [r5, #0x00]
_08056EB6:
	movs r1, #0xEC
	lsls r1, r1, #0x01
	adds r0, r4, r1
	bl TaskPoolDraw
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
