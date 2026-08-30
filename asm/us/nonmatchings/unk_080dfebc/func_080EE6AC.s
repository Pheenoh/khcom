.syntax unified
	.align 2, 0
	.global func_080EE6AC
	.thumb
	.thumb_func
	.type func_080EE6AC, %function
func_080EE6AC: @ 080EE6AC
	push {r4, r5, r6, r7, lr}
	add sp, #-0x00C
	adds r5, r0, #0x0
	movs r1, #0xE1
	lsls r1, r1, #0x04
	bl __udivsi3
	adds r4, r0, #0x0
	mov r6, sp
	movs r1, #0x0A
	bl __udivsi3
	strh r0, [r6, #0x00]
	mov r2, sp
	mov r0, sp
	ldrh r1, [r0, #0x00]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x01
	subs r0, r4, r0
	strh r0, [r2, #0x02]
	lsls r0, r4, #0x03
	subs r0, r0, r4
	lsls r0, r0, #0x05
	adds r0, r0, r4
	lsls r0, r0, #0x04
	subs r5, r5, r0
	adds r0, r5, #0x0
	movs r1, #0x3C
	bl __udivsi3
	adds r4, r0, #0x0
	mov r6, sp
	movs r1, #0x0A
	bl __udivsi3
	strh r0, [r6, #0x04]
	mov r2, sp
	mov r0, sp
	ldrh r1, [r0, #0x04]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x01
	subs r0, r4, r0
	strh r0, [r2, #0x06]
	lsls r0, r4, #0x04
	subs r0, r0, r4
	lsls r0, r0, #0x02
	subs r5, r5, r0
	mov r4, sp
	adds r0, r5, #0x0
	movs r1, #0x0A
	bl __udivsi3
	strh r0, [r4, #0x08]
	mov r2, sp
	mov r0, sp
	ldrh r1, [r0, #0x08]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x01
	subs r5, r5, r0
	strh r5, [r2, #0x0A]
	movs r7, #0x80
	mov r5, sp
	movs r6, #0x05
_080EE730:
	ldrh r4, [r5, #0x00]
	lsls r4, r4, #0x05
	ldr r0, _080EE75C @ =0x09966064
	adds r4, r4, r0
	movs r0, #0x00
	bl func_08005130
	adds r1, r0, #0x0
	adds r1, r1, r7
	adds r0, r4, #0x0
	movs r2, #0x20
	bl func_080043B4
	adds r7, #0x20
	adds r5, #0x02
	subs r6, #0x01
	cmp r6, #0x00
	bge _080EE730
	add sp, #0x00C
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080EE75C: .4byte 0x09966064
.syntax divided
