.syntax unified
	.align 2, 0
	.global func_080EE62C
	.thumb
	.thumb_func
	.type func_080EE62C, %function
func_080EE62C: @ 080EE62C
	push {r4, r5, r6, r7, lr}
	add sp, #-0x008
	adds r4, r0, #0x0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r5, sp
	movs r6, #0x64
	adds r0, r4, #0x0
	movs r1, #0x64
	bl __udivsi3
	strh r0, [r5, #0x00]
	mov r5, sp
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl __udivsi3
	mov r1, sp
	ldrh r2, [r1, #0x00]
	lsls r1, r2, #0x02
	adds r1, r1, r2
	lsls r1, r1, #0x01
	subs r0, r0, r1
	strh r0, [r5, #0x02]
	mov r2, sp
	mov r0, sp
	ldrh r0, [r0, #0x00]
	muls r0, r6
	subs r4, r4, r0
	mov r0, sp
	ldrh r1, [r0, #0x02]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x01
	subs r4, r4, r0
	strh r4, [r2, #0x04]
	movs r6, #0x40
	mov r5, sp
	adds r5, #0x02
	movs r7, #0x01
_080EE67C:
	ldrh r4, [r5, #0x00]
	lsls r4, r4, #0x05
	ldr r0, _080EE6A8 @ =0x09966064
	adds r4, r4, r0
	movs r0, #0x00
	bl GetBgCharBase
	adds r1, r0, #0x0
	adds r1, r1, r6
	adds r0, r4, #0x0
	movs r2, #0x20
	bl RequestDma3Copy
	adds r6, #0x20
	adds r5, #0x02
	subs r7, #0x01
	cmp r7, #0x00
	bge _080EE67C
	add sp, #0x008
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080EE6A8: .4byte 0x09966064
.syntax divided
