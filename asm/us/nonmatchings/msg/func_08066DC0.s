.syntax unified
	.align 2, 0
	.global func_08066DC0
	.thumb
	.thumb_func
	.type func_08066DC0, %function
func_08066DC0: @ 08066DC0
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x010
	adds r4, r0, #0x0
	adds r5, r2, #0x0
	mov r10, r3
	ldr r2, [sp, #0x034]
	ldr r3, [sp, #0x038]
	lsls r4, r4, #0x10
	lsrs r7, r4, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r9, r2
	lsls r3, r3, #0x18
	lsrs r6, r3, #0x18
	movs r4, #0x00
	cmp r4, r6
	bcs _08066E2A
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	lsls r7, r1, #0x10
_08066DF6:
	lsls r0, r4, #0x03
	add r0, r8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r1, [r5, #0x00]
	lsls r1, r1, #0x02
	ldr r2, _08066E3C @ =0x09EEC538
	adds r1, r1, r2
	ldr r2, [r1, #0x00]
	ldr r1, [sp, #0x030]
	str r1, [sp, #0x000]
	movs r1, #0x00
	str r1, [sp, #0x004]
	str r1, [sp, #0x008]
	mov r1, r9
	str r1, [sp, #0x00C]
	asrs r1, r7, #0x10
	mov r3, r10
	bl DrawSprite
	adds r5, #0x02
	adds r1, r4, #0x1
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	cmp r4, r6
	bcc _08066DF6
_08066E2A:
	add sp, #0x010
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08066E3C: .4byte 0x09EEC538
.syntax divided
