.syntax unified
	.align 2, 0
	.global task_bos_lst_fld_1
	.thumb
	.thumb_func
	.type task_bos_lst_fld_1, %function
task_bos_lst_fld_1: @ 081100C0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	bl func_0802F208
	ldr r0, [r5, #0x00]
	cmp r0, #0x01
	beq _081100FC
	cmp r0, #0x02
	beq _08110128
	ldr r0, _081100F8 @ =0x02039B84
	ldr r3, [r0, #0x00]
	ldr r0, [r3, #0x10]
	ldr r1, [r3, #0x08]
	subs r0, r0, r1
	asrs r0, r0, #0x03
	mov r12, r0
	ldr r6, [r3, #0x68]
	ldr r7, [r3, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x0A
	movs r0, #0x00
	adds r1, r7, #0x0
	ands r1, r2
	orrs r0, r1
	cmp r0, #0x00
	beq _08110160
	ldr r0, [r3, #0x14]
	b _08110194
_081100F8: .4byte 0x02039B84
_081100FC:
	ldr r0, _08110124 @ =0x02039B84
	ldr r2, [r0, #0x00]
	adds r0, r2, #0x0
	adds r0, #0xCC
	ldr r0, [r0, #0x00]
	asrs r0, r0, #0x08
	ldr r1, [r2, #0x08]
	subs r0, r0, r1
	asrs r0, r0, #0x03
	mov r12, r0
	adds r0, r2, #0x0
	adds r0, #0xD0
	adds r1, r2, #0x0
	adds r1, #0xD4
	ldr r0, [r0, #0x00]
	ldr r1, [r1, #0x00]
	adds r0, r0, r1
	ldr r1, [r2, #0x0C]
	b _08110196
	.byte 0x00, 0x00
_08110124: .4byte 0x02039B84
_08110128:
	ldr r0, _08110158 @ =0x02039B84
	ldr r2, [r0, #0x00]
	ldr r0, [r2, #0x10]
	ldr r1, [r2, #0x08]
	subs r0, r0, r1
	asrs r0, r0, #0x03
	mov r12, r0
	ldr r1, [r2, #0x7C]
	ldr r0, [r1, #0x08]
	ldr r1, [r1, #0x0C]
	adds r0, r0, r1
	ldr r1, [r2, #0x0C]
	subs r0, r0, r1
	asrs r3, r0, #0x03
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r3, r0
	ble _0811014E
	adds r3, r0, #0x0
_0811014E:
	ldr r0, _0811015C @ =0xFFFFFF00
	cmp r3, r0
	bge _0811019A
	adds r3, r0, #0x0
	b _0811019A
_08110158: .4byte 0x02039B84
_0811015C: .4byte 0xFFFFFF00
_08110160:
	movs r0, #0x80
	lsls r0, r0, #0x0E
	adds r1, r6, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _0811018C
	ldr r1, [r3, #0x7C]
	ldr r2, [r1, #0x0C]
	ldr r0, _08110184 @ =0xFFFF6000
	cmp r2, r0
	bge _08110188
	ldr r0, [r1, #0x08]
	adds r0, r0, r2
	b _08110194
	.byte 0x00, 0x00
_08110184: .4byte 0xFFFF6000
_08110188:
	movs r3, #0x00
	b _0811019A
_0811018C:
	ldr r1, [r3, #0x7C]
	ldr r0, [r1, #0x08]
	ldr r1, [r1, #0x0C]
	adds r0, r0, r1
_08110194:
	ldr r1, [r3, #0x0C]
_08110196:
	subs r0, r0, r1
	asrs r3, r0, #0x03
_0811019A:
	movs r0, #0xA0
	lsls r0, r0, #0x03
	cmp r12, r0
	bgt _081101A8
	ldr r0, _08110228 @ =0xFFFFFB00
	cmp r12, r0
	bge _081101AA
_081101A8:
	add r12, r0
_081101AA:
	ldr r4, _0811022C @ =0x02039B84
	ldr r1, [r4, #0x00]
	ldr r2, [r1, #0x08]
	add r2, r12
	str r2, [r1, #0x08]
	ldr r0, [r1, #0x0C]
	adds r0, r0, r3
	str r0, [r1, #0x0C]
	str r2, [r1, #0x00]
	str r0, [r1, #0x04]
	bl func_0810FEDC
	ldr r1, [r4, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xDA
	movs r2, #0x00
	ldsh r0, [r0, r2]
	adds r0, #0x78
	lsls r0, r0, #0x08
	ldr r2, [r1, #0x00]
	cmp r2, r0
	blt _081101E6
	adds r0, r1, #0x0
	adds r0, #0xDC
	movs r3, #0x00
	ldsh r0, [r0, r3]
	subs r0, #0x78
	lsls r0, r0, #0x08
	cmp r2, r0
	ble _081101E8
_081101E6:
	str r0, [r1, #0x00]
_081101E8:
	ldr r0, _0811022C @ =0x02039B84
	ldr r2, [r0, #0x00]
	ldr r1, [r2, #0x04]
	movs r4, #0xA0
	lsls r4, r4, #0x07
	adds r1, r1, r4
	adds r0, r2, #0x0
	adds r0, #0xE0
	movs r4, #0x00
	ldsh r3, [r0, r4]
	lsls r0, r3, #0x08
	cmp r1, r0
	ble _0811020A
	adds r0, r3, #0x0
	subs r0, #0x50
	lsls r0, r0, #0x08
	str r0, [r2, #0x04]
_0811020A:
	ldr r0, [r5, #0x18]
	adds r0, #0x01
	str r0, [r5, #0x18]
	bl func_08116E8C
	ldr r0, [r5, #0x04]
	cmp r0, #0x01
	bne _0811021C
	b _08110420
_0811021C:
	cmp r0, #0x01
	bgt _08110230
	cmp r0, #0x00
	beq _0811023E
	b _081104EC
	.byte 0x00, 0x00
_08110228: .4byte 0xFFFFFB00
_0811022C: .4byte 0x02039B84
_08110230:
	cmp r0, #0x02
	bne _08110236
	b _0811045E
_08110236:
	cmp r0, #0x03
	bne _0811023C
	b _08110440
_0811023C:
	b _081104EC
_0811023E:
	ldr r1, [r5, #0x0C]
	lsls r1, r1, #0x02
	ldrh r0, [r5, #0x20]
	subs r0, r0, r1
	strh r0, [r5, #0x20]
	movs r3, #0x00
	movs r7, #0x01
	ldr r0, _08110418 @ =0x00001084
	adds r4, r5, r0
	ldr r1, _0811041C @ =0x000001FF
	adds r6, r1, #0x0
_08110254:
	lsls r2, r3, #0x01
	ldr r1, [r5, #0x18]
	ands r1, r7
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x06
	adds r2, r2, r0
	adds r2, r4, r2
	ldrh r1, [r5, #0x20]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsrs r0, r0, #0x02
	ands r0, r6
	strh r0, [r2, #0x00]
	adds r3, #0x01
	cmp r3, #0x17
	ble _08110254
	cmp r3, #0x1F
	bgt _081102AA
	movs r7, #0x01
	ldr r2, _08110418 @ =0x00001084
	adds r4, r5, r2
	ldr r0, _0811041C @ =0x000001FF
	adds r6, r0, #0x0
_08110284:
	lsls r2, r3, #0x01
	ldr r1, [r5, #0x18]
	ands r1, r7
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x06
	adds r2, r2, r0
	adds r2, r4, r2
	ldrh r1, [r5, #0x20]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x04
	subs r0, r0, r1
	asrs r0, r0, #0x06
	ands r0, r6
	strh r0, [r2, #0x00]
	adds r3, #0x01
	cmp r3, #0x1F
	ble _08110284
_081102AA:
	cmp r3, #0x27
	bgt _081102DE
	movs r1, #0x01
	mov r12, r1
	ldr r2, _08110418 @ =0x00001084
	adds r4, r5, r2
	movs r7, #0x2E
	ldr r0, _0811041C @ =0x000001FF
	adds r6, r0, #0x0
_081102BC:
	lsls r2, r3, #0x01
	ldr r1, [r5, #0x18]
	mov r0, r12
	ands r1, r0
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x06
	adds r2, r2, r0
	adds r2, r4, r2
	ldrh r0, [r5, #0x20]
	muls r0, r7
	asrs r0, r0, #0x06
	ands r0, r6
	strh r0, [r2, #0x00]
	adds r3, #0x01
	cmp r3, #0x27
	ble _081102BC
_081102DE:
	cmp r3, #0x2F
	bgt _08110312
	movs r1, #0x01
	mov r12, r1
	ldr r2, _08110418 @ =0x00001084
	adds r4, r5, r2
	movs r7, #0x2C
	ldr r0, _0811041C @ =0x000001FF
	adds r6, r0, #0x0
_081102F0:
	lsls r2, r3, #0x01
	ldr r1, [r5, #0x18]
	mov r0, r12
	ands r1, r0
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x06
	adds r2, r2, r0
	adds r2, r4, r2
	ldrh r0, [r5, #0x20]
	muls r0, r7
	asrs r0, r0, #0x06
	ands r0, r6
	strh r0, [r2, #0x00]
	adds r3, #0x01
	cmp r3, #0x2F
	ble _081102F0
_08110312:
	cmp r3, #0x37
	bgt _08110346
	movs r1, #0x01
	mov r12, r1
	ldr r2, _08110418 @ =0x00001084
	adds r4, r5, r2
	movs r7, #0x2A
	ldr r0, _0811041C @ =0x000001FF
	adds r6, r0, #0x0
_08110324:
	lsls r2, r3, #0x01
	ldr r1, [r5, #0x18]
	mov r0, r12
	ands r1, r0
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x06
	adds r2, r2, r0
	adds r2, r4, r2
	ldrh r0, [r5, #0x20]
	muls r0, r7
	asrs r0, r0, #0x06
	ands r0, r6
	strh r0, [r2, #0x00]
	adds r3, #0x01
	cmp r3, #0x37
	ble _08110324
_08110346:
	cmp r3, #0x3F
	bgt _08110376
	movs r7, #0x01
	ldr r1, _08110418 @ =0x00001084
	adds r4, r5, r1
	ldr r2, _0811041C @ =0x000001FF
	adds r6, r2, #0x0
_08110354:
	lsls r2, r3, #0x01
	ldr r1, [r5, #0x18]
	ands r1, r7
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x06
	adds r2, r2, r0
	adds r2, r4, r2
	ldrh r1, [r5, #0x20]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsrs r0, r0, #0x03
	ands r0, r6
	strh r0, [r2, #0x00]
	adds r3, #0x01
	cmp r3, #0x3F
	ble _08110354
_08110376:
	cmp r3, #0x47
	bgt _081103AA
	movs r4, #0x01
	mov r12, r4
	ldr r0, _08110418 @ =0x00001084
	adds r4, r5, r0
	movs r7, #0x26
	ldr r1, _0811041C @ =0x000001FF
	adds r6, r1, #0x0
_08110388:
	lsls r2, r3, #0x01
	ldr r1, [r5, #0x18]
	mov r0, r12
	ands r1, r0
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x06
	adds r2, r2, r0
	adds r2, r4, r2
	ldrh r0, [r5, #0x20]
	muls r0, r7
	asrs r0, r0, #0x06
	ands r0, r6
	strh r0, [r2, #0x00]
	adds r3, #0x01
	cmp r3, #0x47
	ble _08110388
_081103AA:
	cmp r3, #0x4F
	bgt _081103DA
	movs r7, #0x01
	ldr r1, _08110418 @ =0x00001084
	adds r4, r5, r1
	ldr r2, _0811041C @ =0x000001FF
	adds r6, r2, #0x0
_081103B8:
	lsls r2, r3, #0x01
	ldr r1, [r5, #0x18]
	ands r1, r7
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x06
	adds r2, r2, r0
	adds r2, r4, r2
	ldrh r1, [r5, #0x20]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsrs r0, r0, #0x04
	ands r0, r6
	strh r0, [r2, #0x00]
	adds r3, #0x01
	cmp r3, #0x4F
	ble _081103B8
_081103DA:
	cmp r3, #0x9F
	bgt _08110404
	movs r7, #0x01
	ldr r0, _08110418 @ =0x00001084
	adds r4, r5, r0
	ldr r6, _0811041C @ =0x000001FF
_081103E6:
	lsls r2, r3, #0x01
	ldr r1, [r5, #0x18]
	ands r1, r7
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x06
	adds r2, r2, r0
	adds r2, r4, r2
	ldrh r1, [r5, #0x20]
	adds r0, r6, #0x0
	ands r0, r1
	strh r0, [r2, #0x00]
	adds r3, #0x01
	cmp r3, #0x9F
	ble _081103E6
_08110404:
	ldr r1, [r5, #0x18]
	movs r0, #0x01
	ands r1, r0
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x06
	ldr r1, _08110418 @ =0x00001084
	adds r0, r0, r1
	b _08110452
	.byte 0x00, 0x00
_08110418: .4byte 0x00001084
_0811041C: .4byte 0x000001FF
_08110420:
	ldr r1, [r5, #0x0C]
	lsls r1, r1, #0x02
	ldrh r0, [r5, #0x22]
	subs r0, r0, r1
	strh r0, [r5, #0x22]
	ldr r0, [r5, #0x18]
	ldr r1, _08110438 @ =0x000003FF
	ands r0, r1
	lsls r0, r0, #0x01
	ldr r2, _0811043C @ =0x00000744
	adds r0, r0, r2
	b _08110452
_08110438: .4byte 0x000003FF
_0811043C: .4byte 0x00000744
_08110440:
	ldr r1, [r5, #0x1C]
	ldr r0, [r5, #0x0C]
	muls r1, r0
	ldrh r0, [r5, #0x20]
	subs r0, r0, r1
	strh r0, [r5, #0x20]
	ldrb r0, [r5, #0x18]
	lsls r0, r0, #0x01
	adds r0, #0xC4
_08110452:
	adds r0, r5, r0
	bl func_08116E60
	bl func_08116E80
	b _081104EC
_0811045E:
	ldr r0, [r5, #0x0C]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	ldrh r0, [r5, #0x20]
	subs r0, r0, r1
	strh r0, [r5, #0x20]
	ldrh r0, [r5, #0x22]
	adds r0, #0x03
	strh r0, [r5, #0x22]
	movs r3, #0x00
	movs r7, #0x01
	ldr r0, _0811051C @ =0x00001084
	adds r4, r5, r0
	ldr r6, _08110520 @ =0x000001FF
_0811047A:
	lsls r2, r3, #0x01
	ldr r1, [r5, #0x18]
	ands r1, r7
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x06
	adds r2, r2, r0
	adds r2, r4, r2
	ldrh r1, [r5, #0x22]
	adds r0, r6, #0x0
	ands r0, r1
	strh r0, [r2, #0x00]
	adds r3, #0x01
	cmp r3, #0x7F
	ble _0811047A
	cmp r3, #0x9F
	bgt _081104D2
	movs r1, #0x01
	mov r12, r1
	ldr r2, _0811051C @ =0x00001084
	adds r6, r5, r2
	lsls r0, r3, #0x01
	ldr r1, _08110524 @ =0xFFFFFF00
	adds r4, r0, r1
	ldr r2, _08110520 @ =0x000001FF
	adds r7, r2, #0x0
_081104AE:
	lsls r2, r3, #0x01
	ldr r1, [r5, #0x18]
	mov r0, r12
	ands r1, r0
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x06
	adds r2, r2, r0
	adds r2, r6, r2
	mvns r0, r4
	ldrh r1, [r5, #0x22]
	adds r0, r0, r1
	ands r0, r7
	strh r0, [r2, #0x00]
	adds r4, #0x02
	adds r3, #0x01
	cmp r3, #0x9F
	ble _081104AE
_081104D2:
	ldr r1, [r5, #0x18]
	movs r0, #0x01
	ands r1, r0
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x06
	ldr r2, _0811051C @ =0x00001084
	adds r0, r0, r2
	adds r0, r5, r0
	bl func_08116E60
	bl func_08116E80
_081104EC:
	ldrh r1, [r5, #0x20]
	ldrh r2, [r5, #0x22]
	movs r0, #0x00
	bl SetBgScroll
	ldr r0, [r5, #0x08]
	cmp r0, #0x1F
	beq _081104FE
	b _08110604
_081104FE:
	ldr r0, [r5, #0x10]
	str r0, [r5, #0x04]
	ldr r1, [r5, #0x14]
	str r1, [r5, #0x0C]
	movs r2, #0x00
	strh r2, [r5, #0x20]
	strh r2, [r5, #0x22]
	cmp r0, #0x01
	beq _08110560
	cmp r0, #0x01
	bgt _08110528
	cmp r0, #0x00
	beq _08110532
	b _081105F8
	.byte 0x00, 0x00
_0811051C: .4byte 0x00001084
_08110520: .4byte 0x000001FF
_08110524: .4byte 0xFFFFFF00
_08110528:
	cmp r0, #0x02
	beq _08110580
	cmp r0, #0x03
	beq _081105D0
	b _081105F8
_08110532:
	ldr r1, _08110554 @ =0x09D4B274
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl LoadBgMap
	ldr r0, _08110558 @ =0x04000010
	ldr r2, [r5, #0x18]
	movs r1, #0x01
	ands r2, r1
	lsls r1, r2, #0x02
	adds r1, r1, r2
	lsls r1, r1, #0x06
	ldr r3, _0811055C @ =0x00001084
	adds r1, r1, r3
	adds r1, r5, r1
	b _081105E4
_08110554: .4byte 0x09D4B274
_08110558: .4byte 0x04000010
_0811055C: .4byte 0x00001084
_08110560:
	ldr r1, _08110574 @ =0x09D4BA74
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl LoadBgMap
	ldr r0, _08110578 @ =0x04000010
	ldr r4, _0811057C @ =0x00000744
	adds r1, r5, r4
	b _081105E4
_08110574: .4byte 0x09D4BA74
_08110578: .4byte 0x04000010
_0811057C: .4byte 0x00000744
_08110580:
	lsls r0, r1, #0x04
	subs r0, r0, r1
	lsls r0, r0, #0x03
	negs r0, r0
	strh r0, [r5, #0x20]
	cmp r1, #0x00
	ble _081105A0
	ldr r1, _0811059C @ =0x09D4C274
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl LoadBgMap
	b _081105AC
_0811059C: .4byte 0x09D4C274
_081105A0:
	ldr r1, _081105C4 @ =0x09D4CA74
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl LoadBgMap
_081105AC:
	ldr r0, _081105C8 @ =0x04000012
	ldr r2, [r5, #0x18]
	movs r1, #0x01
	ands r2, r1
	lsls r1, r2, #0x02
	adds r1, r1, r2
	lsls r1, r1, #0x06
	ldr r2, _081105CC @ =0x00001084
	adds r1, r1, r2
	adds r1, r5, r1
	b _081105E4
	.byte 0x00, 0x00
_081105C4: .4byte 0x09D4CA74
_081105C8: .4byte 0x04000012
_081105CC: .4byte 0x00001084
_081105D0:
	str r2, [r5, #0x1C]
	ldr r1, _081105EC @ =0x09D4C274
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl LoadBgMap
	ldr r0, _081105F0 @ =0x04000012
	adds r1, r5, #0x0
	adds r1, #0xC4
_081105E4:
	ldr r2, _081105F4 @ =0xA2600001
	bl func_08116E00
	b _08110604
_081105EC: .4byte 0x09D4C274
_081105F0: .4byte 0x04000012
_081105F4: .4byte 0xA2600001
_081105F8:
	ldr r1, _08110638 @ =0x09D4D274
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl LoadBgMap
_08110604:
	ldr r0, [r5, #0x08]
	cmp r0, #0x3F
	bgt _08110630
	adds r4, r5, #0x0
	adds r4, #0x24
	ldr r1, _0811063C @ =0x09D694F4
	ldr r2, _08110640 @ =0x09A4FC20
	lsls r0, r0, #0x02
	adds r0, r0, r2
	ldr r3, [r0, #0x00]
	adds r0, r4, #0x0
	movs r2, #0x50
	bl func_08110058
	ldr r1, _08110644 @ =0x050000A0
	adds r0, r4, #0x0
	movs r2, #0xA0
	bl LoadPalette
	ldr r0, [r5, #0x08]
	adds r0, #0x01
	str r0, [r5, #0x08]
_08110630:
	movs r0, #0x01
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_08110638: .4byte 0x09D4D274
_0811063C: .4byte 0x09D694F4
_08110640: .4byte 0x09A4FC20
_08110644: .4byte 0x050000A0
.syntax divided
