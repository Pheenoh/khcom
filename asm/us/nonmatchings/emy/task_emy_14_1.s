.syntax unified
	.align 2, 0
	.global task_emy_14_1
	.thumb
	.thumb_func
	.type task_emy_14_1, %function
task_emy_14_1: @ 08038840
	push {r4, r5, r6, lr}
	add sp, #-0x01C
	adds r4, r0, #0x0
	adds r6, r4, #0x0
	adds r5, r4, #0x0
	adds r5, #0x3C
	bl _0800CBDC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0803889A
	adds r0, r5, #0x0
	add r1, sp, #0x018
	movs r2, #0x00
	movs r3, #0x00
	bl func_0801C700
	ldr r0, [r5, #0x04]
	ldr r1, [sp, #0x018]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _08038878
	ldr r0, _08038874 @ =0x000031FF
	cmp r2, r0
	ble _08038880
	b _08038890
_08038874: .4byte 0x000031FF
_08038878:
	subs r1, r1, r0
	ldr r0, _0803888C @ =0x000031FF
	cmp r1, r0
	bgt _08038890
_08038880:
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r0, #0x12
	b _08038898
	.byte 0x00, 0x00
_0803888C: .4byte 0x000031FF
_08038890:
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r0, #0x13
_08038898:
	str r0, [r1, #0x00]
_0803889A:
	movs r1, #0xA6
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldr r0, [r0, #0x00]
	cmp r0, #0x12
	beq _080388AC
	cmp r0, #0x13
	beq _080388EC
	b _08038920
_080388AC:
	ldr r0, _080388E4 @ =0x0813D86C
	adds r1, r6, #0x0
	adds r1, #0x10
	ldr r2, [r6, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x00
	movs r3, #0x00
	bl func_08019068
	movs r0, #0xB3
	str r0, [sp, #0x000]
	movs r0, #0x18
	str r0, [sp, #0x004]
	ldr r0, _080388E8 @ =0x00000242
	str r0, [sp, #0x008]
	movs r0, #0x00
	str r0, [sp, #0x00C]
	str r0, [sp, #0x010]
	movs r0, #0x16
	str r0, [sp, #0x014]
	adds r0, r4, #0x0
	movs r1, #0x0F
	movs r2, #0x0E
	movs r3, #0x14
	bl func_0800C980
	b _08038920
	.byte 0x00, 0x00
_080388E4: .4byte 0x0813D86C
_080388E8: .4byte 0x00000242
_080388EC:
	ldr r0, _08038934 @ =0x0813D86C
	adds r1, r6, #0x0
	adds r1, #0x10
	ldr r2, [r6, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x01
	movs r3, #0x00
	bl func_08019068
	movs r0, #0xB4
	str r0, [sp, #0x000]
	movs r0, #0x64
	str r0, [sp, #0x004]
	ldr r0, _08038938 @ =0x00000221
	str r0, [sp, #0x008]
	movs r0, #0x00
	str r0, [sp, #0x00C]
	str r0, [sp, #0x010]
	movs r0, #0x14
	str r0, [sp, #0x014]
	adds r0, r4, #0x0
	movs r1, #0x14
	movs r2, #0x25
	movs r3, #0x06
	bl func_0800C980
_08038920:
	adds r0, r4, #0x0
	bl _0800CDF0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #0x01C
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08038934: .4byte 0x0813D86C
_08038938: .4byte 0x00000221
.syntax divided
