.syntax unified
	.align 2, 0
	.global func_080B1C14
	.thumb
	.thumb_func
	.type func_080B1C14, %function
func_080B1C14: @ 080B1C14
	push {lr}
	ldr r0, _080B1C24 @ =0x02039828
	ldr r1, [r0, #0x00]
	cmp r1, #0x00
	bne _080B1C2C
	ldr r0, _080B1C28 @ =0x0203AB10
	strb r1, [r0, #0x00]
	b _080B1C32
_080B1C24: .4byte 0x02039828
_080B1C28: .4byte 0x0203AB10
_080B1C2C:
	ldr r1, _080B1C60 @ =0x0203AB10
	movs r0, #0x05
	strb r0, [r1, #0x00]
_080B1C32:
	ldr r0, _080B1C64 @ =0x09EF15A8
	ldr r2, _080B1C68 @ =0x0203AB20
	movs r3, #0x80
	lsls r3, r3, #0x04
	adds r1, r2, #0x0
	adds r1, #0x12
_080B1C3E:
	strh r3, [r1, #0x00]
	subs r1, #0x02
	cmp r1, r2
	bge _080B1C3E
	ldr r2, _080B1C6C @ =0x0203AB34
	movs r3, #0x00
	adds r1, r2, #0x1
_080B1C4C:
	strb r3, [r1, #0x00]
	subs r1, #0x01
	cmp r1, r2
	bge _080B1C4C
	movs r1, #0x80
	lsls r1, r1, #0x04
	bl func_080010CC
	pop {r0}
	bx r0
_080B1C60: .4byte 0x0203AB10
_080B1C64: .4byte 0x09EF15A8
_080B1C68: .4byte 0x0203AB20
_080B1C6C: .4byte 0x0203AB34
.syntax divided
