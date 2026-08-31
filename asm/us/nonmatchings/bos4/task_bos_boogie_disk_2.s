.syntax unified
	.align 2, 0
	.global task_bos_boogie_disk_2
	.thumb
	.thumb_func
	.type task_bos_boogie_disk_2, %function
task_bos_boogie_disk_2: @ 080DAF8C
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x014
	adds r7, r0, #0x0
	adds r5, r7, #0x0
	adds r5, #0x40
	ldr r0, [r5, #0x08]
	bl func_0801AF1C
	adds r4, r0, #0x0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, [r7, #0x0C]
	mov r9, r0
	movs r1, #0xAE
	lsls r1, r1, #0x01
	adds r0, r7, r1
	ldrb r0, [r0, #0x00]
	movs r1, #0x01
	bl func_08002C28
	mov r8, r0
	mov r6, sp
	adds r6, #0x12
	ldr r2, [r5, #0x04]
	ldr r3, [r5, #0x08]
	ldr r0, [r5, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r6, #0x0
	bl WorldToScreen
	adds r0, r7, #0x0
	adds r0, #0x14
	bl AnimGetGfx
	adds r2, r0, #0x0
	add r0, sp, #0x010
	movs r3, #0x00
	ldsh r0, [r0, r3]
	movs r3, #0x00
	ldsh r1, [r6, r3]
	ldr r3, [r7, #0x08]
	mov r6, r9
	str r6, [sp, #0x000]
	mov r6, r8
	str r6, [sp, #0x004]
	str r4, [sp, #0x008]
	ldr r5, [r5, #0x08]
	asrs r5, r5, #0x08
	lsls r5, r5, #0x02
	ldr r6, _080DB01C @ =0xFFFFEFFC
	adds r4, r6, #0x0
	subs r4, r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl DrawSprite
	adds r0, r7, #0x0
	adds r0, #0x2C
	bl TaskPoolDraw
	add sp, #0x014
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080DB01C: .4byte 0xFFFFEFFC
.syntax divided
