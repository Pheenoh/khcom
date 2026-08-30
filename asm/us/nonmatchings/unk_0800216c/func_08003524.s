.syntax unified
	.align 2, 0
	.global func_08003524
	.thumb
	.thumb_func
	.type func_08003524, %function
func_08003524: @ 08003524
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	mov r10, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r9, r1
	movs r2, #0x00
	movs r1, #0x00
	cmp r2, r9
	bcs _08003584
_08003540:
	lsls r0, r1, #0x02
	add r0, r10
	ldr r4, [r0, #0x00]
	ldrh r7, [r4, #0x00]
	adds r4, #0x02
	movs r5, #0x00
	movs r6, #0x00
	adds r1, #0x01
	mov r8, r1
	cmp r5, r7
	bcs _08003574
_08003556:
	ldrh r0, [r4, #0x00]
	ldrh r1, [r4, #0x02]
	str r2, [sp, #0x000]
	bl func_08001DB0
	adds r0, r5, r0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r4, #0x06
	adds r0, r6, #0x1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r2, [sp, #0x000]
	cmp r6, r7
	bcc _08003556
_08003574:
	cmp r2, r5
	bcs _0800357A
	adds r2, r5, #0x0
_0800357A:
	mov r1, r8
	lsls r0, r1, #0x10
	lsrs r1, r0, #0x10
	cmp r1, r9
	bcc _08003540
_08003584:
	lsls r0, r2, #0x15
	lsrs r0, r0, #0x10
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
