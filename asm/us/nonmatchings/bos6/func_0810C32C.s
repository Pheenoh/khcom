.syntax unified
	.align 2, 0
	.global func_0810C32C
	.thumb
	.thumb_func
	.type func_0810C32C, %function
func_0810C32C: @ 0810C32C
	push {r4, lr}
	add sp, #-0x018
	adds r4, r0, #0x0
	adds r2, r1, #0x0
	movs r1, #0x00
	ldrb r0, [r4, #0x02]
	cmp r0, #0x00
	beq _0810C33E
	b _0810C47E
_0810C33E:
	str r2, [sp, #0x000]
	mov r1, sp
	ldrh r0, [r4, #0x12]
	strh r0, [r1, #0x12]
	adds r0, r4, #0x0
	adds r0, #0x74
	str r0, [sp, #0x014]
	ldr r1, [r4, #0x44]
	str r1, [sp, #0x004]
	ldr r0, [r4, #0x48]
	movs r3, #0x80
	lsls r3, r3, #0x03
	adds r0, r0, r3
	str r0, [sp, #0x008]
	ldr r0, [r4, #0x4C]
	ldr r3, _0810C3B8 @ =0xFFFFEC00
	adds r0, r0, r3
	str r0, [sp, #0x00C]
	cmp r2, #0x04
	beq _0810C3C4
	cmp r2, #0x05
	beq _0810C418
	movs r2, #0x12
	ldsh r0, [r4, r2]
	lsls r0, r0, #0x0C
	adds r0, r1, r0
	str r0, [sp, #0x004]
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x15
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x08
	movs r3, #0x80
	lsls r3, r3, #0x04
	adds r0, r0, r3
	ldr r1, [sp, #0x008]
	subs r1, r1, r0
	str r1, [sp, #0x008]
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x11
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x08
	ldr r1, _0810C3BC @ =0xFFFFF800
	adds r0, r0, r1
	ldr r1, [sp, #0x00C]
	adds r1, r1, r0
	str r1, [sp, #0x00C]
	ldr r0, _0810C3C0 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x40
	b _0810C474
	.byte 0x00, 0x00
_0810C3B8: .4byte 0xFFFFEC00
_0810C3BC: .4byte 0xFFFFF800
_0810C3C0: .4byte 0x02039B84
_0810C3C4:
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x11
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x08
	ldr r2, _0810C414 @ =0xFFFFF800
	adds r0, r0, r2
	ldr r1, [sp, #0x004]
	adds r1, r1, r0
	str r1, [sp, #0x004]
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x11
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x08
	ldr r3, _0810C414 @ =0xFFFFF800
	adds r0, r0, r3
	ldr r1, [sp, #0x00C]
	adds r1, r1, r0
	str r1, [sp, #0x00C]
	mov r1, sp
	adds r0, r4, #0x0
	adds r0, #0x7A
	movs r2, #0x00
	ldsh r0, [r0, r2]
	lsls r0, r0, #0x02
	strb r0, [r1, #0x10]
	movs r3, #0x89
	lsls r3, r3, #0x04
	adds r0, r4, r3
	b _0810C474
	.byte 0x00, 0x00
_0810C414: .4byte 0xFFFFF800
_0810C418:
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x21
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x08
	ldr r1, _0810C488 @ =0xFFFFF000
	adds r0, r0, r1
	ldr r1, [sp, #0x004]
	adds r1, r1, r0
	str r1, [sp, #0x004]
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x15
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x08
	movs r2, #0x80
	lsls r2, r2, #0x04
	adds r0, r0, r2
	ldr r1, [sp, #0x008]
	subs r1, r1, r0
	str r1, [sp, #0x008]
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x41
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x08
	ldr r3, _0810C48C @ =0xFFFFE000
	adds r0, r0, r3
	ldr r1, [sp, #0x00C]
	adds r1, r1, r0
	str r1, [sp, #0x00C]
	movs r1, #0x89
	lsls r1, r1, #0x04
	adds r0, r4, r1
_0810C474:
	ldr r1, _0810C490 @ =0x09EF9F0C
	mov r2, sp
	bl func_08000E14
	movs r1, #0x01
_0810C47E:
	adds r0, r1, #0x0
	add sp, #0x018
	pop {r4}
	pop {r1}
	bx r1
_0810C488: .4byte 0xFFFFF000
_0810C48C: .4byte 0xFFFFE000
_0810C490: .4byte 0x09EF9F0C
.syntax divided
