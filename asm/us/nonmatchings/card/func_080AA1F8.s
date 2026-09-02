.syntax unified
	.align 2, 0
	.global func_080AA1F8
	.thumb
	.thumb_func
	.type func_080AA1F8, %function
func_080AA1F8: @ 080AA1F8
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	add sp, #-0x008
	bl func_08084BF0
	adds r4, r0, #0x0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl func_08084BAC
	adds r5, r0, #0x0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	mov r6, sp
	movs r0, #0x64
	mov r8, r0
	adds r0, r4, #0x0
	movs r1, #0x64
	bl __udivsi3
	strb r0, [r6, #0x00]
	mov r6, sp
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl __udivsi3
	mov r1, sp
	ldrb r2, [r1, #0x00]
	lsls r1, r2, #0x02
	adds r1, r1, r2
	lsls r1, r1, #0x01
	subs r0, r0, r1
	strb r0, [r6, #0x01]
	mov r2, sp
	mov r0, sp
	ldrb r0, [r0, #0x00]
	mov r1, r8
	muls r1, r0
	adds r0, r1, #0x0
	subs r4, r4, r0
	mov r0, sp
	ldrb r1, [r0, #0x01]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x01
	subs r4, r4, r0
	strb r4, [r2, #0x02]
	add r4, sp, #0x004
	adds r0, r5, #0x0
	movs r1, #0x64
	bl __udivsi3
	strb r0, [r4, #0x00]
	adds r0, r5, #0x0
	movs r1, #0x0A
	bl __udivsi3
	ldrb r2, [r4, #0x00]
	lsls r1, r2, #0x02
	adds r1, r1, r2
	lsls r1, r1, #0x01
	subs r0, r0, r1
	strb r0, [r4, #0x01]
	adds r0, r2, #0x0
	mov r2, r8
	muls r2, r0
	adds r0, r2, #0x0
	subs r5, r5, r0
	ldrb r1, [r4, #0x01]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x01
	subs r5, r5, r0
	strb r5, [r4, #0x02]
	movs r0, #0x03
	bl GetBgCharBase
	adds r6, r0, #0x0
	mov r0, sp
	ldrb r0, [r0, #0x00]
	adds r0, #0x01
	lsls r0, r0, #0x05
	ldr r5, _080AA324 @ =0x0940F938
	adds r0, r0, r5
	movs r2, #0xA8
	lsls r2, r2, #0x02
	adds r1, r6, r2
	movs r2, #0x20
	bl RequestDma3Copy
	mov r0, sp
	ldrb r0, [r0, #0x01]
	adds r0, #0x01
	lsls r0, r0, #0x05
	adds r0, r0, r5
	movs r2, #0xB0
	lsls r2, r2, #0x02
	adds r1, r6, r2
	movs r2, #0x20
	bl RequestDma3Copy
	mov r0, sp
	ldrb r0, [r0, #0x02]
	adds r0, #0x01
	lsls r0, r0, #0x05
	adds r0, r0, r5
	movs r2, #0xB8
	lsls r2, r2, #0x02
	adds r1, r6, r2
	movs r2, #0x20
	bl RequestDma3Copy
	ldrb r0, [r4, #0x00]
	adds r0, #0x01
	lsls r0, r0, #0x05
	adds r0, r0, r5
	movs r2, #0xC0
	lsls r2, r2, #0x02
	adds r1, r6, r2
	movs r2, #0x20
	bl RequestDma3Copy
	ldrb r0, [r4, #0x01]
	adds r0, #0x01
	lsls r0, r0, #0x05
	adds r0, r0, r5
	movs r2, #0xC8
	lsls r2, r2, #0x02
	adds r1, r6, r2
	movs r2, #0x20
	bl RequestDma3Copy
	ldrb r0, [r4, #0x02]
	adds r0, #0x01
	lsls r0, r0, #0x05
	adds r0, r0, r5
	movs r2, #0xD0
	lsls r2, r2, #0x02
	adds r1, r6, r2
	movs r2, #0x20
	bl RequestDma3Copy
	add sp, #0x008
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080AA324: .4byte 0x0940F938
.syntax divided
