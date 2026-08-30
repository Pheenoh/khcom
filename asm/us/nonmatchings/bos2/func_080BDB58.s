.syntax unified
	.align 2, 0
	.global func_080BDB58
	.thumb
	.thumb_func
	.type func_080BDB58, %function
func_080BDB58: @ 080BDB58
	push {r4, lr}
	ldr r2, _080BDB90 @ =0x0203ACD0
	movs r0, #0x00
	ldsb r0, [r2, r0]
	ldr r3, _080BDB94 @ =0x0203B4E8
	cmp r0, #0x01
	bne _080BDBD4
	ldr r1, _080BDB98 @ =0x0203ACC8
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	ldr r1, _080BDB9C @ =0x0203ACCC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r4, #0x00
	ldsh r1, [r1, r4]
	cmp r0, r1
	bge _080BDBD0
	ldr r0, _080BDBA0 @ =0x0203B4E0
	ldrh r1, [r0, #0x00]
	movs r2, #0x03
	ands r1, r2
	adds r2, r0, #0x0
	cmp r1, #0x00
	bne _080BDBA4
	movs r0, #0x80
	lsls r0, r0, #0x02
	b _080BDBC0
_080BDB90: .4byte 0x0203ACD0
_080BDB94: .4byte 0x0203B4E8
_080BDB98: .4byte 0x0203ACC8
_080BDB9C: .4byte 0x0203ACCC
_080BDBA0: .4byte 0x0203B4E0
_080BDBA4:
	movs r0, #0x00
	ldsh r1, [r2, r0]
	adds r0, r1, #0x0
	cmp r1, #0x00
	bge _080BDBB0
	adds r0, r1, #0x3
_080BDBB0:
	asrs r0, r0, #0x02
	lsls r0, r0, #0x02
	subs r0, r1, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x02
	bne _080BDBC2
	ldr r0, _080BDBCC @ =0xFFFFFE00
_080BDBC0:
	str r0, [r3, #0x00]
_080BDBC2:
	ldrh r0, [r2, #0x00]
	adds r0, #0x01
	strh r0, [r2, #0x00]
	b _080BDBD4
	.byte 0x00, 0x00
_080BDBCC: .4byte 0xFFFFFE00
_080BDBD0:
	movs r0, #0x00
	strb r0, [r2, #0x00]
_080BDBD4:
	ldr r0, [r3, #0x00]
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
