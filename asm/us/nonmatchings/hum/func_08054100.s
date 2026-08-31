.syntax unified
	.align 2, 0
	.global func_08054100
	.thumb
	.thumb_func
	.type func_08054100, %function
func_08054100: @ 08054100
	push {r4, r5, r6, r7, lr}
	add sp, #-0x014
	adds r7, r0, #0x0
	adds r5, r1, #0x0
	ldrh r1, [r5, #0x34]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	bne _08054186
	ldr r0, [r5, #0x30]
	cmp r0, #0x00
	blt _0805411C
	movs r6, #0x00
	b _08054144
_0805411C:
	negs r0, r0
	cmp r0, #0x00
	bge _08054124
	adds r0, #0x7F
_08054124:
	asrs r0, r0, #0x07
	movs r1, #0x80
	lsls r1, r1, #0x01
	subs r2, r1, r0
	cmp r2, #0x7F
	bgt _08054132
	movs r2, #0x80
_08054132:
	movs r3, #0x00
	cmp r2, r1
	ble _0805413A
	movs r3, #0x01
_0805413A:
	movs r0, #0x00
	adds r1, r2, #0x0
	bl AllocObjAffine
	adds r6, r0, #0x0
_08054144:
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r5, #0x28]
	ldr r3, [r5, #0x2C]
	movs r0, #0x00
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl WorldToScreen
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	ldr r2, _08054190 @ =0x08B22BA8
	movs r4, #0x86
	lsls r4, r4, #0x02
	adds r3, r7, r4
	ldr r3, [r3, #0x00]
	movs r5, #0x87
	lsls r5, r5, #0x02
	adds r4, r7, r5
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	str r6, [sp, #0x004]
	movs r4, #0x80
	lsls r4, r4, #0x04
	str r4, [sp, #0x008]
	ldr r4, _08054194 @ =0x0000FFFE
	str r4, [sp, #0x00C]
	bl DrawSprite
_08054186:
	add sp, #0x014
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08054190: .4byte 0x08B22BA8
_08054194: .4byte 0x0000FFFE
.syntax divided
