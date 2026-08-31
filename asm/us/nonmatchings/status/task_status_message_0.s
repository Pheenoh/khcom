.syntax unified
	.align 2, 0
	.global task_status_message_0
	.thumb
	.thumb_func
	.type task_status_message_0, %function
task_status_message_0: @ 080D8A04
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	movs r1, #0x64
	bl func_08065ACC
	movs r0, #0xCA
	lsls r0, r0, #0x02
	adds r2, r4, r0
	ldr r0, [r5, #0x00]
	ldr r1, [r5, #0x04]
	str r0, [r2, #0x00]
	str r1, [r2, #0x04]
	ldr r0, [r2, #0x00]
	adds r1, r4, #0x0
	bl func_08065B6C
	movs r2, #0xC8
	lsls r2, r2, #0x02
	adds r1, r4, r2
	strb r0, [r1, #0x00]
	ldr r0, _080D8A44 @ =0x0984B1B8
	movs r1, #0x20
	bl LoadObjPalette
	movs r1, #0xC9
	lsls r1, r1, #0x02
	adds r4, r4, r1
	str r0, [r4, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
_080D8A44: .4byte 0x0984B1B8
.syntax divided
