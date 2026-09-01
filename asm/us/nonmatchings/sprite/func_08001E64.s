.syntax unified
	.align 2, 0
	.global func_08001E64
	.thumb
	.thumb_func
	.type func_08001E64, %function
func_08001E64: @ 08001E64
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0x0
	mov r12, r1
	mov r8, r2
	mov r0, r12
	add r0, r8
	asrs r0, r0, #0x01
	lsls r0, r0, #0x02
	adds r0, r0, r7
	ldr r0, [r0, #0x00]
	ldrh r6, [r0, #0x14]
	mov r2, r12
	mov r4, r8
	lsls r0, r4, #0x02
	adds r3, r0, r7
	lsls r0, r2, #0x02
	adds r5, r0, r7
	b _08001E9A
_08001E8C:
	ldr r1, [r5, #0x00]
	ldr r0, [r3, #0x00]
	stm r5!, {r0}
	str r1, [r3, #0x00]
	adds r2, #0x01
	subs r3, #0x04
	subs r4, #0x01
_08001E9A:
	ldr r0, [r5, #0x00]
	ldrh r0, [r0, #0x14]
	cmp r0, r6
	bcs _08001EB4
	lsls r0, r2, #0x02
	adds r1, r0, r7
_08001EA6:
	adds r1, #0x04
	adds r5, #0x04
	adds r2, #0x01
	ldr r0, [r1, #0x00]
	ldrh r0, [r0, #0x14]
	cmp r0, r6
	bcc _08001EA6
_08001EB4:
	ldr r0, [r3, #0x00]
	ldrh r0, [r0, #0x14]
	cmp r6, r0
	bcs _08001ECE
	lsls r0, r4, #0x02
	adds r1, r0, r7
_08001EC0:
	subs r1, #0x04
	subs r3, #0x04
	subs r4, #0x01
	ldr r0, [r1, #0x00]
	ldrh r0, [r0, #0x14]
	cmp r6, r0
	bcc _08001EC0
_08001ECE:
	cmp r2, r4
	blt _08001E8C
	subs r2, #0x01
	cmp r12, r2
	bge _08001EE0
	adds r0, r7, #0x0
	mov r1, r12
	bl func_08001E64
_08001EE0:
	adds r1, r4, #0x1
	cmp r1, r8
	bge _08001EEE
	adds r0, r7, #0x0
	mov r2, r8
	bl func_08001E64
_08001EEE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
