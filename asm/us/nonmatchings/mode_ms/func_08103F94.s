.syntax unified
	.align 2, 0
	.global func_08103F94
	.thumb
	.thumb_func
	.type func_08103F94, %function
func_08103F94: @ 08103F94
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x010
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x000]
	movs r6, #0x00
	lsls r1, r0, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0x02
	bgt _08103FBA
	lsrs r1, r1, #0x10
	adds r0, #0x01
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	b _08103FBE
_08103FBA:
	movs r1, #0x00
	movs r3, #0x03
_08103FBE:
	movs r0, #0x00
	str r0, [sp, #0x004]
	movs r4, #0x00
	lsls r0, r1, #0x10
	adds r2, r0, #0x0
	lsls r0, r3, #0x10
	asrs r1, r0, #0x10
	mov r8, r2
	adds r5, r0, #0x0
	cmp r2, r5
	bge _08103FF4
	ldr r7, _081040E4 @ =0x099935A8
	adds r3, r1, #0x0
_08103FD8:
	asrs r2, r2, #0x10
	lsls r1, r2, #0x03
	adds r1, r1, r7
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	ldrh r1, [r1, #0x04]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r2, #0x01
	lsls r2, r2, #0x10
	asrs r0, r2, #0x10
	cmp r0, r3
	blt _08103FD8
_08103FF4:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x0E
	bl EwramAlloc
	mov r10, r0
	movs r1, #0x00
	mov r2, r8
	lsrs r4, r2, #0x10
	lsls r2, r4, #0x10
	asrs r0, r5, #0x10
	cmp r2, r5
	bge _08104082
	mov r9, r0
	ldr r3, [sp, #0x000]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
_08104016:
	asrs r0, r2, #0x0D
	ldr r7, _081040E4 @ =0x099935A8
	adds r0, r0, r7
	ldr r2, [r0, #0x00]
	mov r12, r2
	movs r2, #0x00
	movs r3, #0x04
	ldsh r0, [r0, r3]
	cmp r2, r0
	bge _08104070
	mov r7, r8
	lsls r7, r7, #0x01
	str r7, [sp, #0x00C]
	adds r5, r0, #0x0
_08104032:
	lsls r0, r2, #0x10
	asrs r3, r0, #0x10
	lsls r0, r3, #0x04
	mov r7, r12
	adds r2, r0, r7
	adds r0, r2, #0x0
	adds r0, #0x08
	ldr r7, [sp, #0x00C]
	adds r0, r0, r7
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08104064
	ldr r7, [sp, #0x004]
	adds r0, r7, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x004]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #0x02
	add r0, r10
	str r2, [r0, #0x00]
	adds r1, #0x01
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
_08104064:
	adds r0, r3, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r5
	blt _08104032
_08104070:
	lsls r0, r4, #0x10
	movs r2, #0x80
	lsls r2, r2, #0x09
	adds r0, r0, r2
	lsrs r4, r0, #0x10
	lsls r2, r4, #0x10
	asrs r0, r2, #0x10
	cmp r0, r9
	blt _08104016
_08104082:
	movs r4, #0x00
	lsls r1, r1, #0x10
	str r1, [sp, #0x008]
_08104088:
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x004]
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	movs r5, #0x00
	movs r2, #0x00
	lsls r4, r4, #0x10
	mov r9, r4
	ldr r3, [sp, #0x008]
	cmp r3, #0x00
	ble _0810418C
	ldr r0, _081040E8 @ =0x08F70AB0
	mov r8, r0
_081040AC:
	lsls r0, r2, #0x10
	asrs r3, r0, #0x10
	lsls r0, r3, #0x02
	mov r1, r10
	adds r4, r0, r1
	ldr r2, [r4, #0x00]
	ldr r0, [sp, #0x000]
	lsls r1, r0, #0x10
	asrs r1, r1, #0x0F
	adds r0, r2, #0x0
	adds r0, #0x08
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	adds r0, r5, r0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r7, r5
	bcs _08104180
	ldr r0, [r2, #0x04]
	bl func_0800FC5C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _081040EC
	ldr r0, [r4, #0x00]
	ldrh r6, [r0, #0x00]
	b _0810411A
	.byte 0x00, 0x00
_081040E4: .4byte 0x099935A8
_081040E8: .4byte 0x08F70AB0
_081040EC:
	ldr r0, [r4, #0x00]
	ldrh r1, [r0, #0x00]
	movs r0, #0x34
	muls r0, r1
	add r0, r8
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	beq _08104112
	cmp r0, #0x01
	bgt _08104108
	cmp r0, #0x00
	beq _0810410E
	b _0810411A
_08104108:
	cmp r0, #0x02
	beq _08104116
	b _0810411A
_0810410E:
	movs r6, #0x00
	b _0810411A
_08104112:
	movs r6, #0xC8
	b _0810411A
_08104116:
	movs r6, #0xBE
	lsls r6, r6, #0x01
_0810411A:
	bl func_08103F3C
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0x34
	muls r0, r6
	add r0, r8
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bhi _08104154
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x64
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x09
	bhi _08104154
	movs r1, #0x80
	lsls r1, r1, #0x08
	adds r0, r1, #0x0
	orrs r6, r0
	lsls r0, r6, #0x10
	lsrs r6, r0, #0x10
_08104154:
	mov r2, r9
	asrs r0, r2, #0x0F
	ldr r3, _0810417C @ =0x02035B58
	adds r0, r0, r3
	strh r6, [r0, #0x00]
	adds r0, r6, #0x0
	bl func_08084458
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bge _0810418C
	adds r0, r6, #0x0
	bl func_08060A2C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl func_0810155C
	b _0810418C
	.byte 0x00, 0x00
_0810417C: .4byte 0x02035B58
_08104180:
	adds r0, r3, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r1, [sp, #0x008]
	cmp r0, r1
	blt _081040AC
_0810418C:
	movs r0, #0x80
	lsls r0, r0, #0x09
	add r0, r9
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x04
	bgt _0810419C
	b _08104088
_0810419C:
	mov r0, r10
	bl EwramFree
	add sp, #0x010
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
